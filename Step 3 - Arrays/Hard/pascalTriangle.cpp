
#include <bits/stdc++.h>
using namespace std;
/*
<variation 1 -In this case, we are given the row number r and the column number c, and we need to find out the element at position (r,c).

int nCr(int n, int r)
{
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c)
{
    int element = nCr(r - 1, c - 1);
    return element;
}

int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: " << element << "\n";
    return 0;
}
*/
/*
<variation 2 - Given the row number n. Print the n-th row of Pascal’s triangle.>
*/
/*BruteForce
int nCr(int n, int r)
{
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void pascalTriangle(int n)
{
    // printing the entire row n:
    for (int c = 1; c <= n; c++)
    {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "\n";
}
*/
/*optimal
void pascalTriangle(int n)
{
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    // Printing the rest of the part:
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}
int main()
{
    int n = 5;
    pascalTriangle(n);
    return 0;
}
*/
/*varitation 3 */
vector<int> generateRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); // inserting the 1st element

    // calculate the rest of the elements:
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> ans;

    // store the entire pascal's triangle:
    for (int row = 1; row <= n; row++)
    {
        ans.push_back(generateRow(row));
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}