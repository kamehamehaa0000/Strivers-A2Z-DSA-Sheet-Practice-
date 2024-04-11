#include <bits/stdc++.h>
using namespace std;

// brute Force
int solve(string str)
{
    if (str.size() == 0)
    {
        return 0;
    }
    int maxans = INT_MIN;
    for (int i = 0; i < str.length(); i++)
    {
        unordered_set<int> set;
        for (int j = i; j < str.length(); j++)
        {
            if (set.find(str[j]) != set.end())
            {
                maxans = max(maxans, j - i);
                break;
            }
            set.insert(str[j]);
            maxans = max(maxans, j - i + 1);
        }
    }
    return maxans;
}

// optimal solution ;
int lengthOfLongestSubstring(string str)
{
    vector<int> cnt(128);
    int l = 0;
    int maxLen = 0;
    for (int r = 0; r < str.length(); r++)
    {
        cnt[str[r]]++;
        while (cnt[str[r]] > 1)
        {
            cnt[str[l]]--;
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}

// another way
int lengthOfLongestSubstring(string s)
{
    int maxi = 0;
    int i = 0;
    int j = 0;
    unordered_map<char, int> mpp;
    while (j < s.size())
    {
        mpp[s[j]]++;
        if (mpp.size() == j - i + 1)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }
        else if (mpp.size() < j - i + 1)
        {
            while (mpp.size() < j - i + 1)
            {
                mpp[s[i]]--;
                if (mpp[s[i]] == 0)
                {
                    mpp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return maxi;
}