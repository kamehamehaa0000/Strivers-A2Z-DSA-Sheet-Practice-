#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, int col, vector<vector<int>> graph, vector<int> &vis)
    {
        vis[node] = col;

        for (auto it : graph[node]) // traverse adjacent nodes
        {
            if (vis[it] == -1) // if unvisited
            {
                if (dfs(it, !col, graph, vis) == false)
                {
                    return false;
                }
            }
            else if (vis[it] == col) // if previously coloured and have the same colour
            {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<int> vis(V, -1);

        // for connected components
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == -1)
            {
                if (dfs(i, 0, graph, vis) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

/*BFS SOLUTION*/
bool bfs(int value, vector<vector<int>> grid, vector<int> &visited)
{
    queue<int> q;
    q.push(value);
    visited[value] = 0; // mark as visited

    while (!q.empty())
    {
        vector<int> temp = grid[q.front()]; // for adjacent nodes of the front
        int val = q.front();
        q.pop();

        for (int i = 0; i < temp.size(); i++)
        {
            if (visited[temp[i]] == -1) // if not visited
            {
                visited[temp[i]] = !visited[val]; // color the opposite of front node
                q.push(temp[i]);
            }
            else if (visited[temp[i]] == visited[val])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> visited(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == -1) // if not visited
        {
            if (bfs(i, graph, visited) == false)
            {
                return false;
            }
        }
    }
    return true;
}