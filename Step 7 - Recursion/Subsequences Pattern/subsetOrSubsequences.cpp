#include <bits/stdc++.h>
using namespace std;
/* Subsets */
void helper(vector<vector<int>> &result, vector<int> &nums, int i, vector<int> temp)
{
    if (i >= nums.size())
    {
        result.push_back(temp);
        return;
    }
    // exclude
    helper(result, nums, i + 1, temp);

    // include
    temp.push_back(nums[i]);
    helper(result, nums, i + 1, temp);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> temp;
    helper(result, nums, 0, temp);
    return result;
}

/* Subsequence of string*/
void helperStr(string s, int index, string temp, vector<string> &ans)
{ // baseCase
    if (index == s.length())
    {
        if (temp.length() != 0)
        {
            ans.push_back(temp);
        }
        return;
    }
    // Not including the current letter in subsequence
    helperStr(s, index + 1, temp, ans);

    // Including the current letter in subsequence
    temp.push_back(s[index]);
    helperStr(s, index + 1, temp, ans);
}
vector<string> subsequences(string str)
{
    vector<string> ans;
    string temp = "";
    helperStr(str, 0, temp, ans);

    return ans;
}
