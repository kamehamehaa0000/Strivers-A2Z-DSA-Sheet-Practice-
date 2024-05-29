#include <bits/stdc++.h>
using namespace std;

/*BFS solution*/
class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) // traverse boundary elements
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if (grid[i][j] == 1) // if it is a land then store it in queue
                    {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delrow[] = {-1, 0, +1, 0};
            int delcol[] = {0, +1, +0, -1};

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                // check for valid coordinates and for land cell
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                {
                    if (!vis[nrow][ncol] && grid[nrow][ncol] == 1)
                    {
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // check for unvisited land cell
                if (grid[i][j] == 1 & vis[i][j] == 0)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

/*DFS solution*/
class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, +0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            // check for valid coordinates and for land cell
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
            {
                if (!vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    dfs(nrow, ncol, vis, grid);
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        dfs(i, j, vis, grid);
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};