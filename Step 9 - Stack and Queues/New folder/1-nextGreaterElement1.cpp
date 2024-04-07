#include <bits/stdc++.h>
using namespace std;

// for leetcode variant of the problem
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    stack<int> st;
    unordered_map<int, int> mpp; // element : nge
    vector<int> ans(m, -1);

    st.push(nums2[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums2[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            if (i < n)
            {
                mpp[nums2[i]] = st.top();
            }
        }

        st.push(nums2[i]);
    }

    for (int i = 0; i < m; i++)
    {
        if (mpp[nums1[i]] != 0)
        {
            ans[i] = mpp[nums1[i]];
        }
    }

    return ans;
}
