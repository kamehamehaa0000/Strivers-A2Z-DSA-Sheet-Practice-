#include <bits/stdc++.h>
using namespace std;

/*optimal solution recursion and backtracking*/

bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}
void helper(int ind, string s, vector<string> temp, vector<vector<string>> &ans)
{
    // basecase
    if (ind == s.size())
    {
        ans.push_back(temp);
        return;
    }
    // recursive call
    for (int i = ind; i < s.size(); i++)
    {
        if (isPalindrome(s, ind, i)) // if substring is palindrome
        {
            // include it in temp
            temp.push_back(s.substr(ind, i - ind + 1));
            helper(i + 1, s, temp, ans);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> temp;
    helper(0, s, temp, res);
    return res;
}
