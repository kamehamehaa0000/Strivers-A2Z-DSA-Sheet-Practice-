#include <bits/stdc++.h>
using namespace std;

void helper(string digits, string temp, int ind, string mpp[], vector<string> &ans)
{

    // basecase
    if (ind >= digits.size())
    {
        ans.push_back(temp);
        return;
    }
    int number = digits[ind] - '0';
    string val = mpp[number];

    for (int i = 0; i < val.size(); i++)
    {
        temp.push_back(val[i]);
        helper(digits, temp, ind + 1, mpp, ans);
        temp.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits == "")
    {
        return {};
    }
    string temp;
    int index = 0;
    string mpp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    helper(digits, temp, index, mpp, ans);
    return ans;
}