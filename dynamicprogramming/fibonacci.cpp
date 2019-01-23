/**
 * @file fibonacci.cpp 斐波那契数列的DP编程练习
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

const int MAX = 10;

int memory[MAX];

/**
 * @brief 记忆性的动态规划(自上到下求解)
 * 
 * @param n 
 * @return int 
 */
int fib(int n)
{
    if(memory[n] == -1)
    {
        if(n <= 1)
            memory[n] = n;
        else
            memory[n] = fib(n - 1) + fib(n - 2);
    }

    return memory[n];
}

/**
 * @brief 表格型的动态规划(自下而上求解)
 * 
 * @param n 
 * @return int 
 */
int
fibBottomToTop(int n)
{
    int f[n + 1];
    f[0] = 0, f[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}

int
main()
{
    for(int i = 0; i < MAX; i++)
        memory[i] = -1;
    cout << fib(9) << std::endl;
    cout << fibBottomToTop(9) << std::endl;
    return 0;
}