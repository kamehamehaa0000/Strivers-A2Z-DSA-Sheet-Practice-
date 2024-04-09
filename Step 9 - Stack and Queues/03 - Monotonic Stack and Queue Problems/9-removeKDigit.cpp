#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
    if (num.size() == k)
    {
        return "0";
    }

    stack<char> st;

    for (char ch : num)
    {
        while (!st.empty() && ch < st.top() && k > 0)
        {
            st.pop();
            k--;
        }
        if (st.empty() && ch == '0')
            continue; // handling leading zeroes
        st.push(ch);
    }
    // if there are still digits present in the stack that need to be removed
    while (k != 0 && !st.empty())
    {
        st.pop();
        k--;
    }
    // if string ="" i.e. stack is empty
    if (st.empty())
    {
        return "0";
    }
    // putting stack into a string in correct order
    string ans = "";
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    return ans;
}