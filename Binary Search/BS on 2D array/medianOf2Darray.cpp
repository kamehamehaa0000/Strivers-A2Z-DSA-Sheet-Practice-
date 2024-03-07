// odd no. of integer in mat and sorted row wise
#include <bits/stdc++.h>
using namespace std;
/*brute force
int findMedian(vector<vector<int>> &arr)
{
    int row = arr.size();
    int col = arr[0].size();
    vector<int> median;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            median.push_back(arr[i][j]);
        }
    }
    sort(median.begin(), median.end());
    return median[(row * col) / 2];
}*/
int countSmallerThanMid(vector<int> &row, int mid)
{
    int l = 0, h = row.size() - 1;
    while (l <= h)
    {
        int md = (l + h) / 2;
        if (row[md] <= mid)
        {
            l = md + 1;
        }
        else
        {
            h = md - 1;
        }
    }
    return l;
}
int findMedian(vector<vector<int>> &A)
{

    int n = A.size();
    int m = A[0].size();
    int low = INT_MAX, high = INT_MIN;

    // Find the minimum and maximum elements in the matrix
    for (int i = 0; i < n; ++i)
    {
        low = min(low, A[i][0]);
        high = max(high, A[i][n - 1]);
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += countSmallerThanMid(A[i], mid);
            cout << cnt << " " << mid << " " << i << endl;
        }
        if (cnt <= (n * m) / 2)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return low;
}
int main()
{
    // Example usage
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}};

    int median = findMedian(matrix);

    cout << "Median: " << median << endl;

    return 0;
}