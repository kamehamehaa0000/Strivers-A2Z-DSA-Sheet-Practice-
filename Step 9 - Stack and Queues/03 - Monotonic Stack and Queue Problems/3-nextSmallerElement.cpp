#include <bits/stdc++.h>
using namespace std;

// my solution
void immediateSmaller(vector<int> &a)
{
    int n = a.size();
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = a[i];
        if (st.top() > a[i])
        {
            a[i] = -1;
        }
        else
        {
            a[i] = st.top();
        }
        st.push(curr);
    }
}
/*
    Coding Ninja stack solution
    Time Complexity: O(n)
    Space complexity: O(n)

    Where 'n' is the number of elements in the array.
*/
void immediateSmaller(vector<int> &a)
{
    int n = a.size();

    // Use a stack to store previous element
    stack<int> s;
    s.push(a[0]);

    for (int i = 1; i < n; i++)
    {
        // If the top is greater than the current element then copy the current element to previous
        if (s.top() > a[i])
        {
            a[i - 1] = a[i];
        }
        else
        {
            // Else set it to -1;
            a[i - 1] = -1;
        }

        // Push the current element to top for next Iteration
        s.push(a[i]);
    }

    // Finally for the last element put it as -1
    a[n - 1] = -1;
}

/*
    Coding Ninja Optimal solution without stacks
    Time Complexity: O(n)
    Space complexity: O(1)

    Where 'n' is the number of elements in the array.
*/
void immediateSmaller(vector<int> &a)
{
    int n = a.size();

    // Run a loop from index 0
    for (int i = 0; i < n - 1; i++)
    {
        // Check for the next element
        if (a[i + 1] < a[i])
        {
            a[i] = a[i + 1];
        }
        else
        {
            a[i] = -1;
        }
    }

    // Finally for the last element put it as -1
    a[n - 1] = -1;
}