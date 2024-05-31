#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &prerequisites)
    {

        vector<int> adj[n];
        for (auto it : prerequisites) // building graph
        {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> indegree(n, 0); // finding indegree
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) // pushing nodes with indegree 0 to queue
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int cnt = 0;

        while (!q.empty()) // bfs
        {
            int node = q.front();
            q.pop();
            cnt++;

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if (cnt != n)
        {
            return false;
        }
        return true;
    }
};