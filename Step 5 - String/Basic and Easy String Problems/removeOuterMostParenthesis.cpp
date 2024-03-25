#include <bits/stdc++.h>
using namespace std;
/*Brute force 0(n)
string removeOuterParentheses(string s)
{
    int count = 0;
    string ans = "";
    bool flag = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            count++;
        }
        else if (s[i] == ')')
        {
            count--;
        }
        if (count == 1 && flag == true)
        {
            flag = false;
            continue;
        }
        if (count == 0 && flag == false)
        {
            flag = true;
            continue;
        }
        ans = ans + s[i];
    }
    return ans;
}*/
// also brute force means this is the optimal and will take o(n)
string removeOuterParentheses(string s)
{
    int total = 0;
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' && total == 0)
        {
            total++;
        }
        else if (s[i] == '(' && total > 0)
        {
            ans += '(';
            total++;
        }
        else if (s[i] == ')' && total > 1)
        {
            ans += ')';
            total--;
        }
        else
        {
            total--;
        }
    }

    return ans;
}
