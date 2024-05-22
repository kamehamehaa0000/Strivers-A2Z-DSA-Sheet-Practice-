#include <bits/stdc++.h>
using namespace std;

// representation - 1 - Adajency Matrix
int main()
{
    int n, m; // n-nodes and m-edges
    cin >> n >> m;
    // adjacency matrix for undirected graph space complexity: O(N^2)
    int adj[n + 1][n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; /*instead of 1 write weight in case of weighted graph */
        adj[v][u] = 1; // this statement will be removed in case of directed graph
    }
    return 0;
}

// representation - 2 - Adajency List

// adjacency list for undirected graph - space complexity: O(2E)
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // push pairs if graph is weighted
        adj[v].push_back(u); // remove this line for undirected graph space complexity: O(E)
    }
    return 0;
}

// gfg problem solution for adjacency list
vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges)
{
    // Code here
    vector<vector<int>> adj(V);
    for (auto i : edges)
    {
        adj[i.first].push_back(i.second); // push pairs if graph is weighted
        adj[i.second].push_back(i.first); // push pairs if graph is weighted
    }
    return adj;
}