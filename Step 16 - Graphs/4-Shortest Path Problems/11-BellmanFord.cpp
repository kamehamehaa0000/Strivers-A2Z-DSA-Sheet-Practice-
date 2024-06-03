#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e8);
        dist[S] = 0;

        for (int i = 0; i < V - 1; i++) // for every vertices
        {
            for (auto it : edges) // going to all the edges
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) // u should be prev visisted and new dist should be less than prev for reaching v
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // check negative cycle by Nth relaxation
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                // if any of the edges give less dist than shortest path and
                // dist is getting reduced then there is a cycle
                return {-1};
            }
        }

        return dist;
    }
};