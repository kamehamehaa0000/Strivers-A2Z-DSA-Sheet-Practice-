#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq; // form {diff, {row,col}}.

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == n - 1 && col == m - 1)
            {
                return diff;
            }

            for (int i = 0; i < 4; i++)
            {
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;
                if (nrow < n && ncol < m && nrow >= 0 && ncol >= 0)
                {
                    int newEffort = max(abs(heights[nrow][ncol] - heights[row][col]), diff);
                    if (newEffort < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};