#include <bits/stdc++.h>
using namespace std;

/*
rules-
    if two astroid collide smaller one will explode
    if size is same then both will explode
    if two are moving in same direction they will never collide

*/

/*stack solution */
vector<int> asteroidCollision(vector<int> &arr)
{
    stack<int> st;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && st.top() > 0 && arr[i] < 0) // collision will happen when stack top is +ive and arr[i] is negative
        {
            int sum = st.top() + arr[i];
            if (sum > 0) // if positive asteroid is surviving
            {
                arr[i] = 0; // leave stack as it is
            }
            else if (sum == 0) // if no one is surviving
            {
                st.pop();   // pop the top
                arr[i] = 0; // not push the current asteroid
            }
            else // sum<0 i.e. if negative asteroid is surviving
            {
                st.pop();
            }
        }
        if (arr[i] != 0)
        {
            st.push(arr[i]);
        }
    }
    vector<int> result(st.size());
    int i = st.size() - 1;
    while (!st.empty())
    {
        result[i] = st.top();
        st.pop();
        i--;
    }
    return result;
}

/*approach 2*/

vector<int> asteroidCollision(vector<int> &arr)
{
    int n = arr.size();
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        while (j > 0 && arr[j - 1] > 0 && arr[i] < 0 && arr[j - 1] < abs(arr[i]))
        {
            j--;
        }

        if (j == 0 || arr[i] > 0 || arr[j - 1] < 0)
        {
            arr[j++] = arr[i];
        }
        else if (arr[j - 1] == abs(arr[i]))
        {
            j--;
        }
    }

    vector<int> result(arr.begin(), arr.begin() + j);

    return result;
}
