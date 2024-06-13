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

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DisjointSet ds(n);
        int cntOfExtraEdges = 0;
        for (auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            if (ds.findUltimateParent(u) == ds.findUltimateParent(v))
            {
                cntOfExtraEdges++;
            }
            else
            {
                ds.unionBySize(u, v);
            }
        }

        int cntOfComponents = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
            {
                cntOfComponents++;
            }
        }
        int minOperations = cntOfComponents - 1;
        if (cntOfExtraEdges >= minOperations)
        {
            return minOperations;
        }
        return -1;
    }
};