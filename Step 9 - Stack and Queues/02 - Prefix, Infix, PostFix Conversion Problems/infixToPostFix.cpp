#include <bits/stdc++.h>
using namespace std;

bool isOperand(char ch)
{
    if (ch - 'a' >= 0 && ch - 'a' <= 25)
    {
        return true;
    }
    else if (ch - '0' >= 0 && ch - '0' <= 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string infixToPostfix(string exp)
{
    string ans = "";
    stack<char> s;

    // Precedence of the operators
    unordered_map<char, int> precedence;
    precedence['^'] = 3;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['('] = 0;
    precedence[')'] = 0;

    for (char ch : exp)
    {
        if (isOperand(ch))
        {
            ans += ch;
        }
        // if open bracket
        else if (ch == '(')
        {
            s.push(ch);
        }
        // if closed bracket
        else if (ch == ')')
        {
            // add the char in stack to ans string and
            // Remove from stack till the last opening bracket is not at top
            while (s.top() != '(')
            {
                ans += s.top();
                s.pop();
            }
            s.pop();
        }

        else // if operator
        {
            // Remove lower precedence operators
            while (s.size() && precedence[s.top()] >= precedence[ch])
            {
                ans += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (s.size())
    {
        ans += s.top();
        s.pop();
    }
    return ans;
}