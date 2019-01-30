/**
 * @file findleastcoin.cpp 给定一个数,和三种面值的硬币, 求组成该数所需的最少硬币数目.
 * @author Raymond Zuo (raymond.zuo@live.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

/* 状态转移方程为:
d(i) = min(d(i - vj) + 1) */

#include <iostream>
using std::cout;
using std::endl;

int findleastcoin(int n)
{
    int dp[n];
    dp[0] = 0;

    int mincount = 0;

    for(int i = 1; i <= n; i++)
    {
        mincount = dp[i - 1];        
        int nUsing3 = i - 3;
        int nUsing5 = i - 5;

        if(nUsing3 >= 0 && dp[nUsing3] < mincount)
        {
            mincount = dp[nUsing3];
        }
        if(nUsing5 >= 0 && dp[nUsing5] < mincount)
        {
            mincount = dp[nUsing5];
        }

        mincount +=1;
        dp[i] = mincount;
    }

    return dp[n];
}

int main()
{
    cout << findleastcoin(11) << std::endl;

    return 0;
}