#include <bits/stdc++.h>
using namespace std;

void helper(vector<string> &result, string current, int open, int close, int n)
{
    // base case
    if (current.size() == 2 * n)
    {
        result.push_back(current);
        return;
    }

    // recursive calls
    if (open < n)
    {
        helper(result, current + '(', open + 1, close, n);
    }
    if (close < open)
    {
        helper(result, current + ')', open, close + 1, n);
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> result;
    helper(result, "", 0, 0, n);
    return result;
}