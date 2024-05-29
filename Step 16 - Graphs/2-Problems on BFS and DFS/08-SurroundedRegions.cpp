#include <bits/stdc++.h>
using namespace std;

// leetcode
/*observations - if set of Xs is connected to boundry O then
it can't be converted */
class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat)
    {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            // check for valid coordinates and unvisited Os
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
            {
                if (!vis[nrow][ncol] && mat[nrow][ncol] == 'O')
                {
                    dfs(nrow, ncol, vis, mat);
                }
            }
        }
    }
    void solve(vector<vector<char>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        // traverse first & last row and col , check for unvisited Os
        for (int j = 0; j < m; j++)
        {
            if (!vis[0][j] && mat[0][j] == 'O') // first row
            {
                dfs(0, j, vis, mat);
            }

            if (!vis[n - 1][j] && mat[n - 1][j] == 'O') // last row
            {
                dfs(n - 1, j, vis, mat);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && mat[i][0] == 'O') // first col
            {
                dfs(0, i, vis, mat);
            }

            if (!vis[i][m - 1] && mat[i][m - 1] == 'O') // last col
            {
                dfs(i, m - 1, vis, mat);
            }
        }
        // if unvisited O then convert to X
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }
    }
};

/*Optimised*/
class Solution
{

private:
    void dfs(int i, int j, int &m, int &n, vector<vector<char>> &board)
    {
        board[i][j] = 'A'; // for marking visited
        int dx[] = {-1, 0, +1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int x = 0; x < 4; x++)
        {
            int newi = dx[x] + i;
            int newj = dy[x] + j;
            if (newi >= 0 && newj >= 0 && newi < m && newj < n && board[newi][newj] == 'O')
            {
                dfs(newi, newj, m, n, board);
            }
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && board[i][j] == 'O')
                {
                    dfs(i, j, m, n, board);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'A')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

/*BFS Approach*/
class Solution
{
public:
    void solve(vector<vector<char>> &mat)
    {
        int n = mat.size();
        if (n == 0)
            return;
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 'O' && !vis[i][0])
            {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if (mat[i][m - 1] == 'O' && !vis[i][m - 1])
            {
                q.push({i, m - 1});
                vis[i][m - 1] = 1;
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (mat[0][j] == 'O' && !vis[0][j])
            {
                q.push({0, j});
                vis[0][j] = 1;
            }
            if (mat[n - 1][j] == 'O' && !vis[n - 1][j])
            {
                q.push({n - 1, j});
                vis[n - 1][j] = 1;
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // BFS
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 'O' && !vis[nrow][ncol])
                {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) // Convert all unvisited 'O's to 'X'
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O' && !vis[i][j])
                {
                    mat[i][j] = 'X';
                }
            }
        }
    }
};
