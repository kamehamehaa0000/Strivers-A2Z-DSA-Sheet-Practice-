#include <bits/stdc++.h>
using namespace std;
/*
its the same problem as binary subarray with sum k
but wording is changed - you can say it as count of binary
subarray with sum == k where 1 is odd and 0 is even*/

// Optimal solution
int helper(vector<int> &nums, int k)
{
    if (k < 0)
    {
        return 0;
    }
    int l = 0, r = 0;
    int sum = 0;
    int cnt = 0;
    while (r < nums.size())
    {
        sum += nums[r] % 2; // if odd %2 will give 1 and 0 on even
        while (sum > k)
        {
            sum -= nums[l] % 2;
            l++;
        }
        cnt = cnt + (r - l + 1);
        r++;
    }
    return cnt;
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    return helper(nums, k) - helper(nums, k - 1);
}