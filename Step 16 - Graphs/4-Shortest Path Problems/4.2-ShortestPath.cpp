#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Create an adjacency list of pairs of the form node1 -> {node2, edge weight}
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // pair { dist, node }.

        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1);

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }

        dist[1] = 0;
        pq.push({0, 1}); // Push the source node to the queue.

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int dis = it.first;

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});

                    parent[adjNode] = node; // Update the parent of the adjNode to the recent node where it came from.
                }
            }
        }

        // If distance to a node could not be found, return an array containing -1.
        if (dist[n] == 1e9)
        {
            return {-1};
        }

        // Store the final path in the ‘path’ array.
        vector<int> path;
        int node = n;

        // Iterate backwards from destination to source through the parent array.
        while (parent[node] != node) // while node is not source - parent of node is the node itself when its the source
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        path.push_back(dist[n]);

        reverse(path.begin(), path.end()); // Since the path stored is in a reverse order
        return path;
    }
};
