#include <bits/stdc++.h>
using namespace std;
/*no negative cycle and negative weight in dijkstra*/
class Solution
{ // ElogV - time complexity
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Create a priority queue (min heap) for storing the nodes as a pair {dist,node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distTo(V, INT_MAX);
        distTo[S] = 0; // Source initialised with dist=0.
        pq.push({0, S});
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) // traverse adjacent nodes.
            {
                int v = it[0];
                int w = it[1];
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
                    pq.push({dis + w, v}); // If current distance is smaller, push it into the queue.
                }
            }
        }
        return distTo;
    }
};