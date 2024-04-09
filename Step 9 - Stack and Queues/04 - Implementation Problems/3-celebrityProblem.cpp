#include <bits/stdc++.h>
using namespace std;

// geekforgeek practice solution

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    // put all element inside stack
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    // remove 2 element till stack.size()!=1
    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (M[a][b] == 1) // if a knows b
        {
            st.push(b);
        }
        else // if (M[b][a] == 1) // if b knows a
        {
            st.push(a);
        }
    }
    // verify if st.top is celebrity
    int candidate = st.top();

    bool rowCheck = false;
    int zeroCount = 0;

    for (int i = 0; i < n; i++)
    {
        // celebrity knows no one
        if (M[candidate][i] == 0)
        {
            zeroCount++;
        }
    }
    if (zeroCount == n)
    {
        rowCheck = true;
    }

    bool colCheck = false;
    int oneCount = 0;

    for (int i = 0; i < n; i++)
    {
        // everyone knows celebrity
        if (M[i][candidate] == 1)
        {
            oneCount++;
        }
    }
    if (oneCount == n - 1)
    {
        colCheck = true;
    }

    if (rowCheck == true && colCheck == true)
    {
        return st.top();
    }
    else
    {
        return -1;
    }
}

/*two pointer optimal approach*/
int celebrity(vector<vector<int>> &M, int n)
{
    // Two pointers pointing at start and end of search space.
    int start = 0, end = n - 1;

    while (start < end)
    {
        if (M[start][end] == 0)
        {
            end--; // This means end cannot be celebrity.
        }
        else
        {
            start++; // This means start cannot be celebrity.
        }
    }

    int candidate = start;
    int zeroCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[candidate][i] != 0) // if celebrity knows anyone
        {
            return -1;
        }
        if (i != start && M[i][candidate] != 1) // if everyone doesn't know anyone
        {
            return -1;
        }
    }

    return candidate;
}