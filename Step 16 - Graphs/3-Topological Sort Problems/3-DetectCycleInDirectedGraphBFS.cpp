#include <bits/stdc++.h>
using namespace std;

bool topoSort(int V, vector<int> adj[])
{
    queue<int> q;
    // store indegree
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    // push nodes having indegree 0 to queue
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int cnt;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        // node is in your topo sort
        // so remove it from the indegree
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    if (cnt != V)
    {
        return false;
    }
    return true;
}
bool isCyclic(int V, vector<int> adj[])
{
    if (topoSort(V, adj) == false)
    {
        return true;
    }
    return false;
}
