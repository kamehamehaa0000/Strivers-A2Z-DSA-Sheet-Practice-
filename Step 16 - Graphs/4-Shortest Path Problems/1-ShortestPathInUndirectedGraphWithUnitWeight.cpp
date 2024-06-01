#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {

        vector<int> adj[N];
        for (auto it : edges) // creating adj list
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> dist(N, 1e9);

        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (dist[node] + 1 < dist[it]) // if dist of node we going to is NOT already smaller
                {
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }

        vector<int> ans(N, -1);
        for (int i = 0; i < N; i++)
        {
            if (dist[i] != 1e9)
            {
                ans[i] = dist[i];
            }
        }
        return ans;
    }
};