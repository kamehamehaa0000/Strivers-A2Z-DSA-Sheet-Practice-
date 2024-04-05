#include <bits/stdc++.h>
using namespace std;

// 1. Use a stack of characters.
// 2. When you encounter an opening bracket,push it to top.
// 3. When you encounter a closing bracket,check if top was the opening for it.
//    If yes, pop it from the stack. Otherwise, return false.

bool isValid(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            if (st.empty() || !match(st.top(), c))
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }

    return st.empty();
}

bool match(char open, char close)
{
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}