#include <bits/stdc++.h>
using namespace std;
// using LargestRectangleInaHistogram logic to find the area of each section of matrix
// after area of 1st row add the one of second row to it and find the area of that row and do the same till all the rows are covered
int largestRectangleArea(vector<int> arr)
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
int maximalRectangle(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    if (m == 0)
    {
        return 0;
    }
    int n = matrix[0].size();
    int result = 0;
    vector<int> histogram(n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '1')
            {
                histogram[j] += 1;
            }
            else
            {
                histogram[j] = 0;
            }
        }

        result = max(result, largestRectangleArea(histogram));
    }
    return result;
}