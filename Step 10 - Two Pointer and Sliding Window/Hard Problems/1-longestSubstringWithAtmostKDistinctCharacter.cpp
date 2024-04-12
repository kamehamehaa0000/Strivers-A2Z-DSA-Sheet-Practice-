#include <bits/stdc++.h>
using namespace std;

// brute
int kDistinctChars(int k, string &str)
{
    int maxLen = 0;
    for (int i = 0; i < str.size(); i++)
    {
        unordered_map<char, int> mpp; // char:freq
        for (int j = i; j < str.size(); j++)
        {
            mpp[str[j]]++;
            if (mpp.size() > k)
            {
                break;
            }
            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}
// better
int kDistinctChars(int k, string &str)
{
    int l = 0, r = 0, maxLen = 0;
    unordered_map<int, int> mpp; // {num:freq}
    while (r < str.size())
    {
        mpp[str[r]]++;

        while (mpp.size() > k)
        {
            mpp[str[l]]--;
            if (mpp[str[l]] == 0)
            {
                mpp.erase(str[l]);
            }
            l++;
        }
        if (mpp.size() <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}
// optimal
int kDistinctChars(int k, string &str)
{
    int l = 0, r = 0, maxLen = 0;
    unordered_map<int, int> mpp; // {num:freq}
    while (r < str.size())
    {
        mpp[str[r]]++;

        if (mpp.size() > k)
        {
            mpp[str[l]]--;
            if (mpp[str[l]] == 0)
            {
                mpp.erase(str[l]);
            }
            l++;
        }
        if (mpp.size() <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}