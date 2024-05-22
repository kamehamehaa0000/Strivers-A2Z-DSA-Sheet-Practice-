#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, vector<int> adjList[], vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : adjList[node])
        {
            if (!vis[it])
            {
                dfs(it, adjList, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int v = isConnected.size();
        vector<int> adjList[v];
        // Converting adjacency matrix to adjacency list
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> vis(v, 0);
        int cnt = 0;
        for (int i = 0; i < v; i++)
        {
            if (vis[i] == 0)
            {
                cnt++;
                dfs(i, adjList, vis);
            }
        }
        return cnt;
    }
};
