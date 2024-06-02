#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<pair<int, int>> adj[n + 1]; // n+1 cause not 0 based indexing
        for (auto it : times)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n + 1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty())
        {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int wt = it.second;

                if (wt + time < dist[adjNode])
                {
                    dist[adjNode] = wt + time;
                    pq.push({wt + time, adjNode});
                }
            }
        }
        int maximumDelay = *max_element(dist.begin() + 1, dist.end());
        if (maximumDelay == 1e9)
        {
            return -1;
        }
        return maximumDelay;
    }
};