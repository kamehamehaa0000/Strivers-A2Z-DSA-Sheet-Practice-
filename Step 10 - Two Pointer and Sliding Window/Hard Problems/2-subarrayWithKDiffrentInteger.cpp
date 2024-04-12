#include <bits/stdc++.h>
using namespace std;

// Brute force solution
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        unordered_map<int, int> mpp;
        for (int j = i; j < nums.size(); j++)
        {
            mpp[nums[j]]++;
            if (mpp.size() == k)
            {
                cnt++;
            }
            if (mpp.size() > k)
            {
                break;
            }
        }
    }
    return cnt;
}

/*Optimal solution*/

int helper(vector<int> &nums, int k)
{ // subarray with distinct int <= k
    if (!k)
    {
        return 0;
    }
    int l = 0;
    int r = 0;
    unordered_map<int, int> mpp;
    int cnt = 0;
    while (r < nums.size())
    {
        mpp[nums[r]]++;
        while (mpp.size() > k)
        {
            mpp[nums[l]]--;
            if (mpp[nums[l]] == 0)
            {
                mpp.erase(nums[l]);
            }
            l++;
        }
        cnt = cnt + (r - l + 1);
        r++;
    }
    return cnt;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return helper(nums, k) - helper(nums, k - 1);
}
