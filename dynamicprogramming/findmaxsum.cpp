/**
 * @file findmaxsum.cpp 查找三角形数列从上到下所经过的路径的最大数字之和(详情参考:POJ1163)
 * @author Raymond Zuo (raymond.zuo@live.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-22
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
#define MAX 5

int dp[MAX][MAX];//记忆计算出结果的和
int input[MAX][MAX]; //所有输入的数字

int maxsum(int i, int j)
{
    if(dp[i][j] == -1)
    {
        if(i == MAX)
            dp[i][j] = input[i][j];
        else
        {
            int leftChildNode = maxsum(i + 1, j);
            int rightChildNode = maxsum(i + 1, j + 1);
            dp[i][j] = std::max(leftChildNode, rightChildNode) + input[i][j];
        }
    }
    return dp[i][j];
}

int maxsumBottomToTop(int i, int j)
{
    for(int i = 1; i <= MAX; i++)
        dp[MAX][i] = input[MAX][i];
    
    for(int i = MAX - 1; i > 0; i--)
    {
        for(int j = 1; j <= i; j++)
        {
            dp[i][j] = std::max(dp[i+1][j], dp[i+1][j+1]) + input[i][j];
        }
    }

    return dp[i][j];
}

int main()
{
    int i,j;      
    for(i=1;i<=MAX;i++)     
        for(j=1;j<=i;j++) {         
            cin >> input[i][j];         
            dp[i][j] = -1;     
        }      
    //cout << maxsum(1,1) << std::endl;  
    cout << maxsumBottomToTop(1,1) << std::endl;  
}