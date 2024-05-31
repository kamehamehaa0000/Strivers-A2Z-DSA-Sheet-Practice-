#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfsCycle(int node, vector<int> &vis, vector<int> &pathVis, vector<int> *adj, vector<int> &res)
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto x : adj[node])
        {
            if (!vis[x])
            {
                if (dfsCycle(x, vis, pathVis, adj, res))
                    return true;
            }
            else if (pathVis[x])
                return true;
        }

        pathVis[node] = 0;
        res.push_back(node);

        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {

        int n = numCourses;
        vector<int> adj[n + 1];
        vector<int> vis(n + 1, 0);
        vector<int> pathVis(n + 1, 0);
        vector<int> res;

        for (auto x : prerequisites) // building graph
        {
            adj[x[0]].push_back(x[1]);
        }

        for (int i = 0; i < n; ++i)
        {
            if (!vis[i])
            {
                if (dfsCycle(i, vis, pathVis, adj, res))
                {
                    return {};
                }
            }
        }

        return res;
    }
};