/**
 * @file factorial.cpp 阶乘动态规划练习
 * @author Raymond Zuo (raymond.zuo@live.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-23
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
using std::cout;
#define MAX 10

int dp[MAX];//用于记忆计算过的结果

int factorialTop2Bottom(int n)
{
    if(dp[n] == 0)
    {
        if(n == 0 || n == 1)
            dp[n] = 1;
        else
            dp[n] = n * factorialTop2Bottom(n - 1);
    }

    return dp[n];
}

int factorialBottom2Top(int n)
{
    int f[n + 1];
    f[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        f[i] = i * f[i - 1];
    }

    return f[n];
}

int main()
{
    cout << factorialBottom2Top(5) << std::endl;
    cout << factorialTop2Bottom(5) << std::endl;
}