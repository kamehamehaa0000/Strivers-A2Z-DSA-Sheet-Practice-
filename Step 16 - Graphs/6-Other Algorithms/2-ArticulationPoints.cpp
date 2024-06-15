#include <bits/stdc++.h>
using namespace std;

// node on whose removal graph breaks into components

class Solution
{
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, int toi[], int low[],
             vector<int> &mark, vector<int> adj[])
    {
        vis[node] = 1;
        toi[node] = timer;
        low[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
            {
                continue;
            }
            if (!vis[it])
            {
                dfs(it, node, vis, toi, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= toi[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], toi[it]);
            }
        }
        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        vector<int> vis(n, 0);
        int toi[n];
        int low[n]; // min toi of adj nodes apart from parent and visited nodes

        // calling dfs
        vector<int> mark(n, 0); // to mark a node as articulation point
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, toi, low, mark, adj);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (mark[i] == 1)
            {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0)
        {
            return {-1};
        }
        return ans;
    }
};