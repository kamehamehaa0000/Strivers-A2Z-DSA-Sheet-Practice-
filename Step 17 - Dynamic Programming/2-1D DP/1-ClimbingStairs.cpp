#include <bits/stdc++.h>
using namespace std;

/* same as fibonacci series */
// using dp - tabulation

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// space optimised tabulation
class Solution
{
public:
    int climbStairs(int n)
    {
        int prev2 = 1;
        int prev = 1;

        for (int i = 2; i <= n; i++)
        {
            int cur_i = prev2 + prev;
            prev2 = prev;
            prev = cur_i;
        }
        return prev;
    }
};