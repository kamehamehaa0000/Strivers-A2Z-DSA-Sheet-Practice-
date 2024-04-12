#include <bits/stdc++.h>
using namespace std;
// max len of subarray with atmost 2 types of number

// Brute Force
int findMaxFruits(vector<int> &arr, int n)
{
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> mpp; // num:freq
        for (int j = i; j < n; j++)
        {
            mpp[arr[j]]++;
            if (mpp.size() > 2)
            {
                break;
            }
            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

// better
int findMaxFruits(vector<int> &arr, int n)
{
    int l = 0, r = 0, maxLen = 0;
    unordered_map<int, int> mpp; // {num:freq}
    while (r < arr.size())
    {
        mpp[arr[r]]++;

        if (mpp.size() > 2)
        {
            while (mpp.size() > 2)
            {
                mpp[arr[l]]--;
                if (mpp[arr[l]] == 0)
                {
                    mpp.erase(arr[l]);
                }
                l++;
            }
        }
        if (mpp.size() <= 2)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}

// optimal

int findMaxFruits(vector<int> &arr, int n)
{
    int l = 0, r = 0, maxLen = 0;
    unordered_map<int, int> mpp; // {num:freq}
    while (r < arr.size())
    {
        mpp[arr[r]]++;

        if (mpp.size() > 2)
        {
            mpp[arr[l]]--;
            if (mpp[arr[l]] == 0)
            {
                mpp.erase(arr[l]);
            }
            l++;
        }
        if (mpp.size() <= 2)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}