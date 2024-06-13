#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltParent(int node)
    {
        if (node == parent[node]) // if not connected / not have any parent
        {
            return node;
        }
        return parent[node] = findUltParent(parent[node]); // compressing path
    }

    void unionBySize(int u, int v)
    {
        int u_ultParent = findUltParent(u);
        int v_ultParent = findUltParent(v);
        if (u_ultParent == v_ultParent)
        {
            return;
        }
        // join smaller rank to larger sized
        if (size[u_ultParent] < size[v_ultParent])
        {
            parent[u_ultParent] = v_ultParent;
            size[v_ultParent] += size[u_ultParent]; // increase the size of the node you attached the node to (v is parent of u so increase size of v)
        }
        else
        {
            parent[v_ultParent] = u_ultParent;
            size[u_ultParent] += size[v_ultParent];
        }
    }
};
int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUltParent(3) == ds.findUltParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUltParent(3) == ds.findUltParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    return 0;
}

/*class DisjointSet
{
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

    void union_set(int a, int b)
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
};*/