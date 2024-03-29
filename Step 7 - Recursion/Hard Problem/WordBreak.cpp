#include <bits/stdc++.h>
using namespace std;
/*
// Brute force gives TLE
 bool helper(int i, string s, unordered_set<string> &wordDict)
{
    if (i == s.size())
    {
        return true;
    }

    string temp;
    for (int j = i; j < s.size(); j++)
    {
        temp += s[j];
        if (wordDict.find(temp) != wordDict.end())
        {
            if (helper(j + 1, s, wordDict))
            {
                return true;
            }
        }
    }
    return false;
}
bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> set;
    for (auto it : wordDict)
    {
        set.insert(it);
    }
    return helper(0, s, set);
}
*/

/* recursion + DP*/
bool helper(int i, string s, unordered_set<string> &wordDict, vector<int> &memo)
{
    if (i == s.size())
    {
        return true;
    }
    if (memo[i] != -1)
    {
        return memo[i];
    }

    string temp;
    for (int j = i; j < s.size(); j++)
    {
        temp += s[j];
        if (wordDict.find(temp) != wordDict.end())
        {
            if (helper(j + 1, s, wordDict, memo))
            {
                memo[i] = 1;
                return true;
            }
        }
    }
    memo[i] = 0;
    return false;
}
bool wordBreak(string s, vector<string> &wordDict)
{
    vector<int> memo;
    memo.resize(s.length() + 1, -1);
    unordered_set<string> set;
    for (auto it : wordDict)
    {
        set.insert(it);
    }
    return helper(0, s, set, memo);
}
