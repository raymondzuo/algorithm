/**
 * @file findmaxsumapple.cpp 
 * @author Raymond Zuo (raymond.zuo@live.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-19
 * 
 * @copyright Copyright (c) 2019
 * 平面上有N＊M个格子，每个格子中放着一定数量的苹果。你从左上角的格子开始， 
 * 每一步只能向下走或是向右走，每次走到一个格子上就把格子里的苹果收集起来， 这样下去，你最多能收集到多少个苹果
 * 
 */
#include <iostream>

int findmaxsumapples(int ** arr, int n, int m)
{
    int **dp = new int*[n];
    for(int i = 0; i < n; i++)
        dp[i] = new int[m];

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int nCurrent = arr[i][j];
            int nTop = 0, nLeft = 0;
            if(i - 1 >= 0)
                nTop = dp[i - 1][j];
            if(j - 1 >= 0)
                nLeft = dp[i][j - 1];

            dp[i][j] = (nTop >= nLeft ? nTop : nLeft) + nCurrent; 
        }
    }
    sum = dp[n - 1][m - 1]; 
    for(int i = 0; i < n; i++)
        delete [] dp[i];
    delete [] dp;
    return sum;
}

int main()
{

    int ** arr = new int *[3];
    for(int i = 0; i < 3; i++)
        arr[i] = new int[4];
    for(int i = 0; i < 3;i++)
    {
        for(int j = 0; j < 4; j++)
        {
            arr[i][j] = i + j;
        }
    }
    
    std::cout << "Max sum apples is: " << findmaxsumapples(arr, 3, 4) << std::endl;
    return 0;
}