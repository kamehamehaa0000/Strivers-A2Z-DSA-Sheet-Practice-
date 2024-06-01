#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
            {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {

        // We create a graph first in the form of an adjacency list.
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        int vis[N] = {0};

        stack<int> st; // dfs topo so stack is req

        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                topoSort(i, adj, vis, st);
            }
        }

        // now, we declare a vector ‘dist’ in which we update the value of the nodes’
        // distance from the source vertex after relaxation of a particular node.
        vector<int> dist(N, 1e9);

        dist[0] = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;

                if (dist[node] + wt < dist[v])
                {
                    dist[v] = wt + dist[node];
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e9)
            {
                dist[i] = -1;
            }
        }
        return dist;
    }
};
