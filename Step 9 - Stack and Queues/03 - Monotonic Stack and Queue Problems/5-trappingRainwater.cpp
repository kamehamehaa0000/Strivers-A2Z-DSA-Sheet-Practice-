#include <bits/stdc++.h>
using namespace std;

/*Brute Force gives TLE*/
int trap(vector<int> &arr)
{
    int n = arr.size();
    int waterTrapped = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int leftMax, rightMax = 0;
        while (j >= 0)
        {
            leftMax = max(leftMax, arr[j]);
            j--;
        }
        j = i;
        while (j < n)
        {
            rightMax = max(rightMax, arr[j]);
            j++;
        }
        waterTrapped += min(leftMax, rightMax) - arr[i];
    }
    return waterTrapped;
}

/*better Solution -- uses prefix sum and suffix sum to precalculate all the left max and right max for each index of array*/
int trap(vector<int> &arr)
{
    int n = arr.size();
    int prefixMax[n];
    int suffixMax[n];
    int maxi = INT_MAX;
    prefixMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixMax[i] = max(prefixMax[i - 1], arr[i]);
    }
    suffixMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], arr[i]);
    }
    int waterTrapped = 0;
    for (int i = 0; i < n; i++)
    {
        waterTrapped += min(prefixMax[i], suffixMax[i]) - arr[i];
    }
    return waterTrapped;
}

/*better using two pointer*/
int trap(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            int curr = arr[i];
            int top = st.top();
            st.pop();
            if (st.empty())
            {
                break;
            }
            int distance = i - st.top() - 1; // distance = current - top()-1
            ans += (min(arr[st.top()], curr) - curr) * distance;
        }
        st.push(i);
    }
    return ans;
}

/*optimal using 2 pointer*/
int trap(vector<int> &arr)
{
    int n = arr.size();
    int l = 0, r = n - 1;
    int trapped = 0;
    int leftMax, rightMax = 0;
    while (l <= r)
    {
        if (arr[l] <= arr[r])
        {
            if (arr[l] >= leftMax)
            {
                leftMax = arr[l];
            }
            else
            {
                trapped += leftMax - arr[l];
            }
            l++;
        }
        else
        {
            if (arr[r] > rightMax)
            {
                rightMax = arr[r];
            }
            else
            {
                trapped += rightMax - arr[r];
            }
            r--;
        }
    }
    return trapped;
}