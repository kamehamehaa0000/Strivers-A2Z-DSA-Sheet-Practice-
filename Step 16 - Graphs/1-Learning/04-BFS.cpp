#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        queue<int> q;

        vector<int> bfs;
        vis[0] = 1;
        q.push(0);

        while (!q.empty())
        {
            int node = q.front(); // level
            q.pop();
            bfs.push_back(node);
            for (auto it : adj[node]) // traverse for all its neighbours
            {
                // if the neighbour has previously not been visited,
                // store in Q and mark as visited
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector<int> adj[6];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector<int> ans = obj.bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}
