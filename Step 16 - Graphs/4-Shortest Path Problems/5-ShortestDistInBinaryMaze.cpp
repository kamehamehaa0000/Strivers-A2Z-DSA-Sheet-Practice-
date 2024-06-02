#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    const int n = grid.size();
    if (grid[0][0] == 0 && n == 1)
    {
        return 1;
    }
    if (grid[0][0] == 1 || grid.back().back() == 1)
    {
        return -1;
    }
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    queue<pair<int, pair<int, int>>> q; //{wt,{i,j}}
    q.push({1, {0, 0}});                // in gfg que it would be 0 cause the source is given and we start at that
    dist[0][0] = 0;
    int delrow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int delcol[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    while (!q.empty())
    {
        int dis = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < grid[0].size())
            {
                if (grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]) /* grid[nrow][ncol]==0 since visited path is 0 in question*/
                {
                    dist[nrow][ncol] = dis + 1;
                    if (nrow == n - 1 && ncol == n - 1)
                    {
                        return dist[nrow][ncol];
                    }
                    q.push({1 + dis, {nrow, ncol}});
                }
            }
        }
    }
    return -1;
}