#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty())
        {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> q; // position, time
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cntFresh = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                if (grid[i][j] == 1)
                {
                    cntFresh++;
                }
            }
        }

        int time = 0;
        int cnt = 0;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nextRow = row + delRow[i];
                int nextCol = col + delCol[i];

                if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n)
                {
                    if (vis[nextRow][nextCol] != 2 && grid[nextRow][nextCol] == 1)
                    {
                        q.push({{nextRow, nextCol}, t + 1});
                        vis[nextRow][nextCol] = 2;
                        cnt++;
                    }
                }
            }
        }
        if (cntFresh != cnt)
        {
            return -1;
        }

        return time;
    }
};
