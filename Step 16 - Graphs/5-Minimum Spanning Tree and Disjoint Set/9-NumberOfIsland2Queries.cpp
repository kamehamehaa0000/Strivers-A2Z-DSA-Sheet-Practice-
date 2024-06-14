#include <bits/stdc++.h>
using namespace std;
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
private:
    bool isValid(int adjr, int adjc, int n, int m)
    {
        return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
    }

public:
    vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q)
    {
        DisjointSet ds(n * m);
        int vis[n][m];
        memset(vis, 0, sizeof vis); // makes vis's every element 0
        int cnt = 0;
        vector<int> ans;
        for (auto it : q)
        {
            int row = it[0];
            int col = it[1];
            if (vis[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int ind = 0; ind < 4; ind++)
            {
                int adjr = row + dr[ind];
                int adjc = col + dc[ind];
                if (isValid(adjr, adjc, n, m)) // check for out of boundry
                {
                    if (vis[adjr][adjc] == 1) // if adj is island
                    {
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjr * m + adjc;
                        if (ds.findUltimateParent(nodeNo) != ds.findUltimateParent(adjNodeNo))
                        {
                            cnt--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

/// solution 2

int dx[4] = {0, 1, -1, 0};

int dy[4] = {1, 0, 0, -1};

class DSU
{

public:
    vector<int> parent;

    int numIsland;

    DSU(int n)

    {

        parent.resize(n);

        numIsland = 0;

        for (int i = 0; i < n; i++)

            parent[i] = i;
    }

    int findParent(int node)

    {

        if (node == parent[node])

            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionn(int x, int y)

    {

        x = findParent(x);

        y = findParent(y);

        if (x == y)

            return;

        parent[y] = x;

        numIsland--;
    }
};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q)
{

    DSU dsu(n * m);

    set<pair<int, int>> s;

    vector<int> ans;

    for (auto it : q)

    {

        dsu.numIsland++;

        s.insert({it[0], it[1]});

        for (int i = 0; i < 4; i++)

        {

            int x = it[0] + dx[i];

            int y = it[1] + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && s.find({x, y}) != s.end())

                dsu.unionn(it[0] * m + it[1], x * m + y);
        }

        ans.push_back(dsu.numIsland);
    }

    return ans;
}
