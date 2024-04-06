#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}
int getPriority(char C)
{
    if (C == '-' || C == '+')
    {
        return 1;
    }
    else if (C == '*' || C == '/')
    {
        return 2;
    }
    else if (C == '^')
    {
        return 3;
    }
    return 0;
}
string infixToPrefix(string infix)
{
    /* Reverse String
     * Replace ( with ) and vice versa
     * Get Postfix
     * Reverse Postfix  *  */
    int l = infix.size();
    // Reverse infix
    reverse(infix.begin(), infix.end());

    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++)
    {

        if (infix[i] == '(')
        {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
            i++;
        }
    }
    // infix to postfix  (Get Postfix)
    stack<char> st;
    string prefix = "";
    for (char ch : infix)
    {
        if (!isOperator(ch))
        {
            prefix += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (st.top() != '(')
            {
                prefix += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (st.size() && getPriority(st.top()) >= getPriority(ch))
            {
                prefix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (st.size())
    {
        prefix += st.top();
        st.pop();
    }

    // Reverse postfix
    reverse(prefix.begin(), prefix.end());

    return prefix;
}
int main()
{
    string s = ("(p+q)*(c-d)");
    cout << "Infix expression: " << s << endl;
    cout << "Prefix Expression: " << infixToPrefix(s) << endl;
    return 0;
}
