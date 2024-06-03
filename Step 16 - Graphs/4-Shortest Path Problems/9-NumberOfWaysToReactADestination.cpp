#include <bits/stdc++.h>
using namespace std;

// no of shortest path

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, int>> adj[n];
        for (auto i : roads)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        pq.push({0, 0});

        vector<long long> dist(n, 1e15);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        int mod = (int)1e9 + 7;

        while (!pq.empty())
        {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                long long edW = it.second;

                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    ways[adjNode] = ways[node];
                    pq.push({dis + edW, adjNode});
                }

                else if (dis + edW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};
