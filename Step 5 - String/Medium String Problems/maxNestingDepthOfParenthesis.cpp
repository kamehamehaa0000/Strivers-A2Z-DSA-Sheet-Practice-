#include <bits/stdc++.h>
using namespace std;
/*Brute force
int maxDepth(string s)
{ // if string is unbalanced or empty
    if (s == "" || s == "(" || s == ")")
    {
        return -1;
    }

    stack<char> st;
    int maxDepth = 0;
    int currDepth = 0;

    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == '(')
        {
            st.push(s[i]);
            currDepth++;
            maxDepth = max(currDepth, maxDepth);
        }
        if (s[i] == ')')
        {
            st.pop();
            currDepth--;
        }
    }
    if (!st.empty())
    {
        return -1;
        // cause a balanced parenthesis string will have empty stack in the end
    }
    return maxDepth;
}*/

// better/optimal solution
int maxDepth(string s)
{
    // if string is unbalanced or empty
    if (s == "" || s == "(" || s == ")")
    {
        return -1;
    }
    int maxDepth = 0;
    int currDepth = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            currDepth++;
        }
        if (s[i] == ')')
        {
            currDepth--;
        }
        maxDepth = max(currDepth, maxDepth);
    }
    if (currDepth != 0)
    {
        return -1; // to handle unbalanced parenthesis
    }
    return maxDepth;
}

int main()
{
    string s = "(((A))(B))";
    cout << maxDepth(s);

    return 0;
}