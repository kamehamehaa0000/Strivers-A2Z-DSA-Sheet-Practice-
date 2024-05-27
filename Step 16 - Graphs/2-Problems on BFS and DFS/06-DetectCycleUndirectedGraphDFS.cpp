#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool detect(int node, int parent, vector<int> adj[], int vis[])
    {
        vis[node] = 1;
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                if (detect(i, node, adj, vis))
                {
                    return true;
                }
            }
            else if (parent != i)
            {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        for (int i = 0; i < V; i++) /* this is cause IF graph is made up of connected components */
        {
            if (!vis[i])
            {
                if (detect(i, -1, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
