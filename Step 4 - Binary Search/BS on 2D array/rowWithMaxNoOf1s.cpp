#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int cnt_max = 0;
    int index = -1;

    // traverse the matrix:
    for (int i = 0; i < n; i++)
    {
        int cnt_ones = 0;
        //will have to optimise this part later
        for (int j = 0; j < m; j++)
        {
            cnt_ones += matrix[i][j];
        }
        if (cnt_ones > cnt_max)
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}
*/
int lowerBound(vector<int> arr, int n)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= 1)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int countMax = 0;
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        int countOfOne = m - lowerBound(matrix[i], m); // m-lowerbound will be the sum of1 or count you can say since array is sorted
        if (countOfOne > countMax)
        {
            countMax = countOfOne;
            index = i;
        }
    }
    return index;
}
int main()
{
    vector<vector<int>> matrix = {{0, 0, 0, 1}, {1, 0, 1, 0}, {0, 0, 0, 0}};
    int n = 3, m = 4;
    cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m) << '\n';
}
