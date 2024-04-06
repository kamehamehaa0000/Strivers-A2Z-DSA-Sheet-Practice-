#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string &s)
{
    stack<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string ans = s[i] + op2 + op1;
            st.push(ans);
        }
        else
        {
            st.push(string(1, s[i]));
        }
    }

    return st.top();
}