#include <bits/stdc++.h>
using namespace std;

// using disjointSet
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
            return v;
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
int maxRemove(vector<vector<int>> &stones, int n)
{
    int maxRow = 0;
    int maxCol = 0;
    // find dimension of grid
    for (auto it : stones)
    {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }
    DisjointSet ds(maxRow + maxCol + 1);
    unordered_map<int, int> stoneNodes; // {row,col}
    for (auto it : stones)
    {
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;
        ds.unionBySize(nodeRow, nodeCol);
        stoneNodes[nodeRow] = 1;
        stoneNodes[nodeCol] = 1;
    }
    int cnt = 0;
    for (auto it : stoneNodes) // if ultimate parent of stone is same then it is in same component
    {
        if (ds.findUltimateParent(it.first) == it.first)
        {
            cnt++;
        }
    }
    return n - cnt;
} // dfs union set solution
class Solution
{
public:
    void dfs(vector<vector<int>> &stones, int index, vector<bool> &visited, int &n)
    {
        visited[index] = true;
        for (int i = 0; i < n; i++)
            if (!visited[i])
            {
                if (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1])
                {
                    dfs(stones, i, visited, n);
                }
            }
    }
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        vector<bool> visited(n, 0);
        int cnt = 0; // no. of connected components
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                continue;
            }
            dfs(stones, i, visited, n);
            cnt++;
        }
        return n - cnt; // total - no. of connected components
    }
};
//[ [ 0, 0 ], [ 0, 1 ], [ 1, 0 ], [ 1, 2 ], [ 2, 1 ], [ 2, 2 ] ]