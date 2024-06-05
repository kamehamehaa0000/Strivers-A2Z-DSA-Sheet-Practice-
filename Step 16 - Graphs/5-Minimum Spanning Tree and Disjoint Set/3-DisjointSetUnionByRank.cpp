#include <bits/stdc++.h>
using namespace std;
// union set - to find parent and union
/*Given an array A[] that stores all number from 1 to N (both inclusive and sorted) and K queries.

The task is to do the following operations on array elements :

1. UNION X Z : Perform union of X and Z i.e. parent of Z will become the parent of X.
2. FIND X: Find the ultimate parent of X and print it.*/

/*gfg solution

int find(int A[],int X)
{
    if(X==A[X])return X;
    return A[X]=find(A,A[X]);
}
void unionSet(int A[],int X,int Z)
{
    A[find(A,X)]=find(A,Z);
}

*/

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
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

    void unionByRank(int u, int v)
    {
        int u_ultParent = findUltParent(u);
        int v_ultParent = findUltParent(v);
        if (u_ultParent == v_ultParent)
        {
            return;
        }
        // join smaller rank to larger ranked
        if (rank[u_ultParent] < rank[v_ultParent])
        {
            parent[u_ultParent] = v_ultParent;
        }
        else if (rank[v_ultParent] < rank[u_ultParent])
        {
            parent[v_ultParent] = u_ultParent;
        }
        else
        { // if rank is same attack them and
            // increase the rank to whom you have attached to
            parent[v_ultParent] = u_ultParent; // it could have been opposite , rank of v would be increased in that case
            rank[u_ultParent]++;
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findUltParent(3) == ds.findUltParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUltParent(3) == ds.findUltParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    return 0;
}
