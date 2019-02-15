/**
 * @file findLis.cpp 查找最长非降序子序列的长度
 * @author Raymond Zuo (raymond.zuo@live.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */

// 5,3,4,8,6,7 最长非降序子序列: 3,4,6,7,则长度为4

#include <iostream>
#include <cstring>

int FindLis(int * arr)
{
    int nSize = sizeof(arr);
    int dp[nSize];
    memset(dp, 0, nSize);    
    int maxlen = 1;

    for(int i = 0; i < nSize; i++)
    {
        dp[i] = 1;
        int lastindex = i;
        for(int j = 0; j < nSize; j++)
        {
            if(arr[j] >= arr[lastindex])
            {
                dp[j] = dp[lastindex] + 1;
                lastindex = j;
                if(dp[j] > maxlen)
                    maxlen = dp[j];
            }
        }
    }

    return maxlen;
}

int FindLisV2(int * arr)
{
    int nSize = sizeof(arr);
    int dp[nSize];
    memset(dp, 0, nSize);    
    int maxlen = 1;

    for(int i = 0; i < nSize; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(arr[j] <= arr[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
        if(dp[i] > maxlen)
            maxlen = dp[i];
    }

    return maxlen;
}

int main()
{
    int arr[5] = {5,3,4,8,7};
    //std::cout << "Longest increasing sequence length is: " << FindLis(arr);
    std::cout << "Longest increasing sequence length is: " << FindLisV2(arr);

    return 0;
}