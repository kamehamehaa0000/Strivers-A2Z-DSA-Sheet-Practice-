/*
Dynamic Programming can be described as storing answers to various sub-problems to be used later whenever required to solve the main problem.

The two common dynamic programming approaches are:

Memoization: Known as the “top-down” dynamic programming,
usually the problem is solved in the direction of the main problem to the base cases.

Tabulation: Known as the “bottom-up '' dynamic programming,
usually the problem is solved in the direction of solving the base cases to the main problem

Note: The base case does not always mean smaller input. It depends upon the implementation of the algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

// memoisation of fibonacci series
int f(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1) // step-2 check if already computed and stored in dp array if not then compute and store it
    {
        return dp[n];
    }
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

int fibonacciMemoized(int n)
{
    vector<int> dp(n + 1, -1); // step 1 - make a 1d array of n+1 size
    cout << f(n, dp) << endl;
}

// tabulation of fibonacci series

int fibonacciTabulation(int n)
{
    vector<int> dp(n + 1, -1); // step 1 - make a 1d array of n+1 size
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2]; // store the value in dp array
    }
    cout << dp[n] << endl;
}

int main()
{
    fibonacciMemoized(4);
    fibonacciTabulation(5);

    // fibonacci 3 pointer solution
    int n = 4;
    int prev2 = 0;
    int prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    }
    cout << prev;
    return 0;
}