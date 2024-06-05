#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V, 0);
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;          //{wt,node} //add parent too if mst is needed here cost is req
        pq.push({0, 0}); // donn't mark visited here

        int cost = 0;

        while (!pq.empty())
        {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if (vis[node] == 1)
            {
                continue;
            }
            vis[node] = 1;
            cost += wt;
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeWt = it[1];

                if (!vis[adjNode])
                {
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        return cost;
    }
};