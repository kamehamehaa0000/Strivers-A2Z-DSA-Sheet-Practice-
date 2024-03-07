#include <bits/stdc++.h>
using namespace std;

vector<int> printSpiral(vector<vector<int>> mat)
{
    // right bottom left top
    // last round will not have top action
    vector<int> ans;
    int n = mat.size();
    int m = mat[0].size();

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        { // left to right
            ans.push_back(mat[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        { // top to bottom (from right end )
            ans.push_back(mat[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                // right to left
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {

            for (int i = bottom; i >= top; i--)
            {
                // bottom  to top
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int main()
{

    // Matrix initialization.
    vector<vector<int>> mat{{1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}};

    vector<int> ans = printSpiral(mat);

    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}