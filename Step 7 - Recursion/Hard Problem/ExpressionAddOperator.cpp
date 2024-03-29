#include <bits/stdc++.h>
using namespace std;

void helper(int index, string num, int target, string curr, vector<string> &ans, long prev, long result)
{
    if (index == num.size())
    {
        if (result == target)
        {
            ans.push_back(curr);
        }
        return;
    }
    string st = "";
    long currResult = 0;
    for (int i = index; i < num.size(); i++)
    {
        if (i > index && num[index] == '0')
        {
            break;
        }
        st += num[i];
        currResult = currResult * 10 + num[i] - '0';
        if (index == 0)
        {
            helper(i + 1, num, target, st, ans, currResult, currResult);
        }
        else
        {
            helper(i + 1, num, target, curr + "+" + st, ans, currResult, result + currResult);
            helper(i + 1, num, target, curr + "-" + st, ans, currResult * -1, result - currResult);
            helper(i + 1, num, target, curr + "*" + st, ans, prev * currResult, result - prev + (prev * currResult));
        }
    }
}
vector<string> addOperators(string num, int target)
{
    vector<string> ans;
    helper(0, num, target, "", ans, 0, 0);
    return ans;
}
