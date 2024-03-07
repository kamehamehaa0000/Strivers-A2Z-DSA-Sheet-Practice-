#include <bits/stdc++.h>
using namespace std;
/* Brute Force
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();

    // traverse the matrix:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}*/
/* Better solution using binary search
bool binarySearch(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return true;
        }
        else if (target > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix[0].size();
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] <= target && target <= matrix[i][m - 1])
        {
            return binarySearch(matrix[i], target);
        }
    }
    return false;
}*/
/*optimal solution -- imagine the 2d array as 1d (flatten it in mind )*/
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // convert 1d coordinate to 2d cordinate
    //  row = ind/m and col = ind%m =>>>> 2d cordinate in form arr[row][col]
    int m = matrix[0].size();
    int n = matrix.size();
    int low = 0;
    int high = (m * n) - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (matrix[mid / m][mid % m] == target)
        {
            return true;
        }
        else if (matrix[mid / m][mid % m] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}
