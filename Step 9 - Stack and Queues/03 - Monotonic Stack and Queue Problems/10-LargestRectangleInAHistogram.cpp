#include <bits/stdc++.h>
using namespace std;

// brute force gives TLE
int largestRectangleArea(vector<int> &arr)
{
    int n = arr.size();
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int minHeight = INT_MAX;
        for (int j = i; j < n; j++)
        {
            minHeight = min(minHeight, arr[j]);
            maxArea = max(maxArea, minHeight * (j - i + 1));
        }
    }
    return maxArea;
}

//------------------------------------------------------------------------------------

/*better */

int largestRectangleArea(vector<int> &arr)
{
    // find next left and right smaller element
    // area = (rightsmaller - leftsmaller + 1) * arr[i]
    int n = arr.size();
    stack<int> st;
    int leftsmall[n];
    int rightsmall[n];
    // calculating left smaller
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            leftsmall[i] = 0;
        }
        else
        {
            leftsmall[i] = st.top() + 1;
        }
        st.push(i);
    }
    // clear the stack to be re-used
    while (!st.empty())
    {
        st.pop();
    }
    // calculating right smalller
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            rightsmall[i] = n - 1;
        }
        else
        {
            rightsmall[i] = st.top() - 1;
        }
        st.push(i);
    }
    int maxA = 0;
    for (int i = 0; i < n; i++)
    {
        maxA = max(maxA, arr[i] * (rightsmall[i] - leftsmall[i] + 1));
    }
    return maxA;
}

//------------------------------------------------------------------------------------

/*optimal solution -  one pass solution of above approach */
int largestRectangleArea(vector<int> &arr)
{
    stack<int> st;
    int maxA = 0;
    int n = arr.size();
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || arr[st.top()] >= arr[i]))
        {
            int height = arr[st.top()];
            st.pop();
            int width;
            if (st.empty())
            {
                width = i;
            }
            else
            {
                width = i - st.top() - 1;
            }
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}