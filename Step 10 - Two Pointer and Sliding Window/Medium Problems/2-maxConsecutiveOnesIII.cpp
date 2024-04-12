#include <bits/stdc++.h>
using namespace std;

// Brute force

int longestOnes(vector<int> &nums, int k)
{
    int maxLen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int cnt = 0;
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j] == 0)
            {
                cnt++;
            }
            if (cnt <= k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }

    return maxLen;
}

// better

int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0;
    int r = 0;
    int zeroCnt = 0;
    int maxLen = 0;
    while (r < n)
    {

        if (nums[r] == 0)
        {
            zeroCnt++;
        }
        while (zeroCnt > k)
        {
            if (nums[l] == 0)
            {
                zeroCnt--;
            }
            l++;
        }
        if (zeroCnt <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}

// optimal
int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0;
    int r = 0;
    int zeroCnt = 0;
    int maxLen = 0;
    while (r < n)
    {
        if (nums[r] == 0)
        {
            zeroCnt++;
        }
        if (zeroCnt > k)
        {
            if (nums[l] == 0)
            {
                zeroCnt--;
            }
            l++;
        }
        if (zeroCnt <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}