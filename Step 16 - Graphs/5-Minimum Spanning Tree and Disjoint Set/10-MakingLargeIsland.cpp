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
    bool isValid(int row, int col, int n)
    {
        return row >= 0 && row < n && col >= 0 && col < n;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                {
                    continue;
                }
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++)
                {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n))
                    {
                        if (grid[newr][newc] == 1)
                        {
                            int nodeNo = row * n + col;
                            int adjNodeNo = newr * n + newc;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }
        int maxi = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                {
                    continue;
                }
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for (int ind = 0; ind < 4; ind++)
                {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n))
                    {
                        if (grid[newr][newc] == 1)
                        {
                            components.insert(ds.findUltimateParent(newr * n + newc));
                        }
                    }
                }
                int sizeTotal = 0;
                for (auto it : components)
                {
                    sizeTotal += ds.size[it];
                }
                maxi = max(maxi, sizeTotal + 1);
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++)
        {
            maxi = max(maxi, ds.size[ds.findUltimateParent(cellNo)]);
        }
        return maxi;
    }
};