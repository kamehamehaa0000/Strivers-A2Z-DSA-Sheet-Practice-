#include <bits/stdc++.h>
using namespace std;
/* Solution 1
void helper(int i, int j, vector<vector<int>> &mat, int n, vector<string> &ans, string move, vector<vector<int>> &temp)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }

    // downward
    if (i + 1 < n && temp[i + 1][j] != 1 && mat[i + 1][j] == 1) // if not visited and not out of bound and is traversable
    {
        temp[i][j] = 1;
        helper(i + 1, j, mat, n, ans, move + 'D', temp);
        temp[i][j] = 0;
    }

    // left
    if (j - 1 >= 0 && temp[i][j - 1] != 1 && mat[i][j - 1] == 1)
    {
        temp[i][j] = 1;
        helper(i, j - 1, mat, n, ans, move + 'L', temp);
        temp[i][j] = 0;
    }

    // right
    if (j + 1 < n && temp[i][j + 1] != 1 && mat[i][j + 1] == 1)
    {
        temp[i][j] = 1;
        helper(i, j + 1, mat, n, ans, move + 'R', temp);
        temp[i][j] = 0;
    }

    // upward
    if (i - 1 >= 0 && temp[i - 1][j] != 1 && mat[i - 1][j] == 1)
    {
        temp[i][j] = 1;
        helper(i - 1, j, mat, n, ans, move + 'U', temp);
        temp[i][j] = 0;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    vector<vector<int>> temp(n, vector<int>(n, 0)); // to track visited cell;

    if (m[0][0] == 1)
    {
        helper(0, 0, m, n, ans, "", temp);
    }
    return ans;
}
*/

////---------------------------------------------------------------------------------------------------

/*Optimised solution*/
void helper(int i, int j, vector<vector<int>> &mat, int n, vector<string> &ans, string move, vector<vector<int>> &temp, int di[], int dj[])
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++)
    {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && temp[nexti][nextj] != 1 && mat[nexti][nextj] == 1)
        {
            temp[i][j] = 1;
            helper(nexti, nextj, mat, n, ans, move + dir[ind], temp, di, dj);
            temp[i][j] = 0;
        }
    }
}
vector<string> ratMaze(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<string> ans;
    vector<vector<int>> temp(n, vector<int>(n, 0)); // to track visited cell;

    int di[] = {+1, 0, 0, -1}; // D L R U
    int dj[] = {0, -1, 1, 0};  // D L R U

    if (mat[0][0] == 1)
    {
        helper(0, 0, mat, n, ans, "", temp, di, dj);
    }
    return ans;
}

//---------------------------------------------------------------------------------------------------------------------------------------

/*Coding ninja's solution that they provide they did not use the visited matrix but changed the 1 to 0 to show its visited*/
/*
    Time Complexity: O(3^(N^2))
    Space Complexity: O(N*N)

    Where 'N*N' is the total number of cells in the maze.
*/
void solve(int i, int j, string path, vector<vector<int>> &matrix, int row, int column, vector<string> &ans)
{
    // Checking out of bounds conditions.
    if (i < 0 or i >= row or j < 0 or j >= column)
    {
        return;
    }
    // Avoid recursive calls on blocked or visited numbers.
    if (matrix[i][j] == 0)
    {
        return;
    }

    // If reached the destination, add the path to the answer vector.
    if (i == row - 1 and j == column - 1)
    {
        ans.push_back(path);
    }

    // Mark the current cell as visited (0).
    matrix[i][j] = 0;

    // Recursive calls for exploring the next possible moves.
    // Up
    solve(i - 1, j, path + 'U', matrix, row, column, ans);
    // Down
    solve(i + 1, j, path + 'D', matrix, row, column, ans);
    // Left
    solve(i, j - 1, path + 'L', matrix, row, column, ans);
    // Right
    solve(i, j + 1, path + 'R', matrix, row, column, ans);

    // Restore the current cell to its original state (1).
    matrix[i][j] = 1;
    return;
}

vector<string> ratMaze(vector<vector<int>> &mat)
{
    string path = "";
    int n = mat.size();
    vector<string> ans;
    solve(0, 0, path, mat, n, n, ans);
    return ans;
}
