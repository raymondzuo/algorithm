/**
 * @file findsumways.cpp 利用给定的几个数, 求有多少种方案可以求和得到另一个指定的数
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

int dp[10];
/**
 * @brief 假设给定1,3,5 Top to Bottom方式
 * 
 * @param n 
 * @return int 
 */
int findsumwaysT2B(int n)
{
    if (dp[n] == 0)
    {
        if (n == 0)
            dp[n] = 1;
        else if(n < 0)
            dp[n] = 0;
        else
            /*状态转移方程: state(n) = state(n - 1) + state(n - 3) + state(n -5)*/
            dp[n] = findsumwaysT2B(n - 1) + findsumwaysT2B(n - 3) + findsumwaysT2B(n -5);
    }

    return dp[n];
}

int findsumwaysB2T(int n)
{
    int dp2[10]; 
    dp2[0] = 1;
    dp2[1] = 1; 
    dp2[2] = 1;
    for(int i = 3; i <=n; i++)
    {
        int below1, below3, below5;
        if(i - 1 < 0)
            below1 = 0;
        else
            below1 = dp2[i - 1];

        if(i - 3 < 0)
            below3 = 0;
        else
            below3 = dp2[i - 3];

        if(i - 5 < 0)
            below5 = 0;
        else
            below5 = dp2[i - 5];

        dp2[i] = below1 + below3 + below5;
    }

    return dp2[n];
}

int main()
{
    cout << findsumwaysT2B(6) << std::endl;
    cout << findsumwaysB2T(6) << std::endl;
    return 0;
}