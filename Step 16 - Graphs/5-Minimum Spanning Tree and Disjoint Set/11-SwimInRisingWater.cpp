#include <bits/stdc++.h>
using namespace std;
/*using djikstra */
class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq; //{val,i,j}
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        pq.push({grid[0][0], 0, 0}); //{val,i,j}
        vis[0][0] = true;

        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();

            int dx[4] = {0, 1, 0, -1};
            int dy[4] = {1, 0, -1, 0};
            for (int i = 0; i < 4; i++)
            {
                int x = node[1] + dx[i];
                int y = node[2] + dy[i];
                if (x < 0 || y < 0 || x >= n || y >= n) // boundry check
                {
                    continue;
                }
                if (vis[x][y])
                {
                    continue;
                }
                // if reached final node,return the max of currentnodes's val or grid positions val
                if (x == n - 1 and y == n - 1)
                {
                    return max(grid[n - 1][n - 1], node[0]);
                }

                vis[x][y] = true;
                int n_max = max(node[0], grid[x][y]);
                pq.push({n_max, x, y});
            }
        }
        return 0;
    }
};

/*using disjoint set*/
class DisjointSet
{
public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int maxSize)
    {
        parent.resize(maxSize);
        size.resize(maxSize);
        for (int i = 0; i < maxSize; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int v)
    {
        if (v == parent[v])
        {
            return v;
        }
        return parent[v] = findUltimateParent(parent[v]);
    }

    void unionBySize(int a, int b)
    {
        a = findUltimateParent(a);
        b = findUltimateParent(b);
        if (a != b)
        {
            if (size[a] < size[b])
            {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();

        DisjointSet ds(n * n);

        // store the location of the element reachable exactly at time t.
        pair<int, int> location[n * n];

        vector<vector<int>> vis(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                location[grid[i][j]] = {i, j};
            }
        }

        vector<int> row = {-1, 0, 0, 1};
        vector<int> col = {0, -1, 1, 0};

        for (int time = 0; time < n * n; time++)
        {
            int x = location[time].first;
            int y = location[time].second;

            vis[x][y] = 1;

            // check if all it's neighbours, if they have already been reached then merge with it.
            for (int a = 0; a < 4; a++)
            {
                int r = x + row[a];
                int c = y + col[a];

                if (r >= 0 && c >= 0 && r < n && c < n && vis[r][c] == 1)
                {
                    int node = x * n + y;
                    int adjnode = r * n + c;
                    ds.unionBySize(node, adjnode);
                }
            }
            // if last element location in the connected component
            if (ds.findUltimateParent(0) == ds.findUltimateParent(n * n - 1))
                return time;
        }
        // max time
        return n * n - 1;
    }
};