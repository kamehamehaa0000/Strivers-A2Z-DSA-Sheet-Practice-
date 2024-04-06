#include <bits/stdc++.h>
using namespace std;

string prefixToInfixConversion(string &s)
{
    stack<string> st;
    string res;
    reverse(s.begin(), s.end());
    for (char c : s)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            st.push(string(1, c));
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push("(" + op1 + c + op2 + ")");
        }
    }
    return st.top();
}

//--------------------------------------------------------------------------
// without reverse funtion
string prefixToInfixConversion(string &s)
{
    stack<string> operands;
    int n = s.size();
    // Iterating from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        // Check if the current character is a operator
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            // Taking last two operands from the stack
            string operand1 = operands.top();
            operands.pop();
            string operand2 = operands.top();
            operands.pop();

            // Combining the two operands with the current operator
            // and pushing back to the stack
            string resultantOfTwo = "(" + operand1 + s[i] + operand2 + ")";
            operands.push(resultantOfTwo);
        }
        else

        {
            // Converting the character str[i] into string
            // and pushing it into the stack
            string strTemp(1, s[i]);
            operands.push(strTemp);
        }
    }

    // Last operand in the stack will be the final answer
    return operands.top();
}
