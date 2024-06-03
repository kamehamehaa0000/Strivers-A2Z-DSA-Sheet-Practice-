#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        // creating adajacency matrix for directred graph to implement floyd warshall
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (auto it : edges)
        {
            // remember to fill both ways
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0; // marking diagonal zero
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    { // if not reachable
                        continue;
                    }
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int maxCity = n;
        int ans = -1;
        for (int city = 0; city < n; city++)
        {
            int cnt = 0;
            for (int adjCity = 0; adjCity < n; adjCity++)
            {
                if (dist[city][adjCity] <= distanceThreshold)
                {
                    cnt++;
                }
            }
            // if cnt is less than maxcnt make maxcnt = cnt
            if (cnt <= maxCity)
            {
                maxCity = cnt;
                ans = city;
            }
        }
        return ans;
    }
};