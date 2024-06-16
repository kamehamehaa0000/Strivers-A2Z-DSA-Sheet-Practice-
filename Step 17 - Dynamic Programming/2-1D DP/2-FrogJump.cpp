#include <bits/stdc++.h>
using namespace std;

// gfg version

// using recursion - will give TLE
class Solution
{
public:
    int solve(int index, vector<int> &heights)
    { // base condition
        if (index = 0)
        {
            return 0;
        }

        int jumpOne = solve(index - 1, heights) + abs(heights[index] - heights[index - 1]);
        if (index > 1)
        {
            int jumpTwo = solve(index - 2, heights) + abs(heights[index] - heights[index - 2]);
            return min(jumpOne, jumpTwo);
        }
        return jumpOne;
    }
    int minimumEnergy(vector<int> &height, int n)
    {
        return solve(n, height);
    }
};

// dp-memoisation
class Solution
{
public:
    int solve(int index, vector<int> &heights, vector<int> &dp)
    { // base condition
        if (index = 0)
        {
            return 0;
        }
        // check for solution in dp array
        if (dp[index] != -1)
        {
            return dp[index];
        }
        // compute and store in dp array
        int jumpOne = solve(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
        if (index > 1)
        {
            int jumpTwo = solve(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);
            return dp[index] = min(jumpOne, jumpTwo);
        }
        return dp[index] = jumpOne;
    }
    int minimumEnergy(vector<int> &height, int n)
    {
        vector<int> dp(n + 1, -1); // create dp array
        return solve(n, height, dp);
    }
};

// dp-tabulation
class Solution
{
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int ind = 1; ind < n; ind++)
        {
            int jumpTwo = INT_MAX;
            int jumpOne = dp[ind - 1] + abs(height[ind] - height[ind - 1]);
            if (ind > 1)
            {
                jumpTwo = dp[ind - 2] + abs(height[ind] - height[ind - 2]);
            }
            dp[ind] = min(jumpOne, jumpTwo);
        }
        return dp[n - 1];
    }
};

// dp space optimised
class Solution
{
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        if (n == 1)
            return 0;
        int prev = 0;
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int jumpone = prev + abs(height[i] - height[i - 1]);
            int jumptwo = INT_MAX;
            if (i > 1)
            {
                jumptwo = prev2 + abs(height[i] - height[i - 2]);
            }
            int current = min(jumpone, jumptwo);
            prev2 = prev;
            prev = current;
        }
        return prev;
    }
};

// for k jumps
int frogJump(int n, vector<int> &heights, int k)
{
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i >= j)
            {
                dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
            }
        }
    }
    return dp[n - 1];
}

// leetcode frog jump solution - 2d dp
class Solution
{
public:
    bool solve(int index, int steps, int n, vector<int> &stones,
               vector<vector<int>> &dp)
    {

        if (index == stones.size() - 1)
        {
            return true;
        }
        if (dp[index][steps] != -1)
        {
            return dp[index][steps];
        }
        for (int i = index + 1; i < n; i++)
        {
            if (stones[i] - stones[index] > steps + 1)
            { // unreachable stone
                break;
            }
            if (stones[i] - stones[index] <
                steps - 1)
            { // reachable with less one steps
                continue;
            }
            if (solve(i, stones[i] - stones[index], n, stones, dp))
            {
                return dp[i][stones[i] - stones[index]] = true;
            }
        }
        return dp[index][steps] = false;
    }
    bool canCross(vector<int> &stones)
    {
        if (stones[1] > 1)
        {
            return false;
        }
        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(1, 1, n, stones, dp);
    }
};