#include <bits/stdc++.h>
using namespace std;
/*brute force
vector<int> findPeakElement(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            bool isPeak = true;

            // Check if the current element is greater than its neighbors
            if (i > 0 && matrix[i][j] <= matrix[i - 1][j])
            {
                isPeak = false; // top
            }
            if (i < n - 1 && matrix[i][j] <= matrix[i + 1][j])
            {
                isPeak = false; // bottom
            }
            if (j > 0 && matrix[i][j] <= matrix[i][j - 1])
            {
                isPeak = false; // left
            }
            if (j < m - 1 && matrix[i][j] <= matrix[i][j + 1])
            {
                isPeak = false; // right
            }

            // If the current element is a peak, return its indices
            if (isPeak)
            {
                return make_pair{i, j};
            }
        }
    }
}*/
/*optimal*/
vector<int> findPeakElement(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;      // at 0th col
    int high = m - 1; // at last col

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int maxRow = 0;
        // to find the max element in the mid column
        for (int row = 0; row < n; row++)
        {
            if (matrix[row][mid] > matrix[maxRow][mid])
            {
                maxRow = row;
            }
        }

        // checking left right
        int left = mid == 0 ? -1 : matrix[maxRow][mid - 1];
        int right = mid == m - 1 ? -1 : matrix[maxRow][mid + 1];
        if (matrix[maxRow][mid] > left && matrix[maxRow][mid] > right)
        {
            return {maxRow, mid};
        }
        else if (left > matrix[maxRow][mid])
        {
            high = mid - 1;
        }
        else // if(right > matrix[maxRow][mid])
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    vector<int> peakElement = findPeakElement(matrix);

    cout << peakElement[0] << " , " << peakElement[1];

    return 0;
}