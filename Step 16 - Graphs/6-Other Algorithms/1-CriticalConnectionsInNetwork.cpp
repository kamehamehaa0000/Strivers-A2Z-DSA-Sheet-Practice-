#include <bits/stdc++.h>
using namespace std;

// using Tarjan's algo
// time of insertion - step you reach a node in dfs
// low array - min lowest time of insertion of all adjacent nodes apart form parents
class Solution
{
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis,
             vector<int> adj[], int toi[], int low[],
             vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        toi[node] = timer;
        low[node] = timer;
        timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
            {
                continue;
            }
            if (!vis[it]) // if adj is not visited
            {
                dfs(it, node, vis, adj, toi, low, bridges);
                low[node] = min(low[it], low[node]);
                if (low[it] > toi[node]) // lowest toi of parent should be greater than toi of child
                {
                    bridges.push_back({it, node});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        // building adj list
        vector<int> adj[n];
        for (auto it : connections)
        {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int toi[n]; // array to record of time of insertion
        int low[n]; // array to keep record of min ToI of all adj nodes except the parent
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, toi, low, bridges);
        return bridges;
    }
};