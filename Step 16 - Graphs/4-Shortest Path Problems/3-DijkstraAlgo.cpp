#include <bits/stdc++.h>
using namespace std;

/*using set*/
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // note - set ds stores the nodes in ascending order of the distances
        set<pair<int, int>> st; // pair {dist,node}

        vector<int> dist(V, 1e9);

        st.insert({0, S});
        dist[S] = 0; // Source initialised with dist=0

        while (!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgW = it[1];

                if (dis + edgW < dist[adjNode])
                {
                    // erase if it was visited previously at a greater cost.
                    if (dist[adjNode] != 1e9)
                    {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};