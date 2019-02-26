#include <iostream>
//#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;

int knapsack(int W, int * wt, int * val, int n)
{
    if(0 ==W || 0 == n)
        return 0;
    if(wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);
    else
    {
        return std::max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1), 
                        knapsack(W, wt, val, n - 1));
    }
}

int main()
{
    int W = 25, n = 4;
    int wt[n] = {22, 10, 9, 7};
    int val[n] = {12, 9, 9, 6};
    cout << knapsack(W, wt, val, n) << endl;

    return 0;
}