#include <bits/stdc++.h>
using namespace std;
// only valid for directed graphs
class Solution
{
public:
    // Function to perform DFS and store nodes according to their finishing times
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    // Function to perform DFS on the reversed graph
    void dfsOnReverse(int node, vector<int> &vis, vector<vector<int>> &reversedEdgesGraph)
    {
        vis[node] = 1;
        for (auto it : reversedEdgesGraph[node])
        {
            if (!vis[it])
            {
                dfsOnReverse(it, vis, reversedEdgesGraph);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // Step 1: Perform DFS to sort nodes by finishing times and store them in a stack
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }

        // Step 2: Reverse all the edges of the graph
        vector<vector<int>> reversedEdgesGraph(V);
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                // Normally i -> it, reversed it -> i
                reversedEdgesGraph[it].push_back(i);
            }
        }

        // Step 3: Perform DFS on the reversed graph in the order of the stack
        int stronglyConnectedComponents = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                stronglyConnectedComponents++;
                dfsOnReverse(node, vis, reversedEdgesGraph);
            }
        }

        return stronglyConnectedComponents;
    }
};