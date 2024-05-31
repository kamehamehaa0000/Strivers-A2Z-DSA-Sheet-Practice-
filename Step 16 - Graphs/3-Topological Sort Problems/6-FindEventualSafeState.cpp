#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<int> indegree(V, 0);
        // make graph with reversed edges and calculating indegree
        vector<int> adjRev[V];
        for (int i = 0; i < V; i++)
        {
            for (auto it : graph[i])
            {
                // in non rev graph i was going to it
                // in reversed graph it will go to i
                // hence increasing the indegree of i
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        // push node with indegree 0 (terminal node) to queue
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        // bfs
        vector<int> safeNodes;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (auto it : adjRev[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};