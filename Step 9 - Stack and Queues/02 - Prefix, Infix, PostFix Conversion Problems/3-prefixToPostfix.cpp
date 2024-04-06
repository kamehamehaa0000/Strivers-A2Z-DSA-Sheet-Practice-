#include <bits/stdc++.h>
using namespace std;

string preToPost(string s)
{
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string ans = op1 + op2 + s[i];
            st.push(ans);
        }
        else
        {
            st.push(string(1, s[i]));
        }
    }

    return st.top();
}