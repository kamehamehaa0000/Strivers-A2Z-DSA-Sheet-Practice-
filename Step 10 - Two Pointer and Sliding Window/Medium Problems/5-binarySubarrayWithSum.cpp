#include <bits/stdc++.h>
using namespace std;

// optimal solution

// helper funtion finds out no. of subarray with sum less than or equal to goal
int helper(vector<int> &nums, int goal)
{
    int l = 0, r = 0;
    int cnt = 0;
    int sum = 0;
    if (goal < 0)
    {
        return 0;
    }
    while (r < nums.size())
    {
        sum += nums[r];
        while (sum > goal)
        {
            sum -= nums[l];
            l++;
        }
        if (sum <= goal)
        {
            cnt = cnt + (r - l + 1);
        }
        r++;
    }
    return cnt;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    // helper(n,goal) - helper(n,goal-1)
    return helper(nums, goal) - helper(nums, goal - 1);
}