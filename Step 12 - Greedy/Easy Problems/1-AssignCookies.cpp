#include <bits/stdc++.h>
using namespace std;

// serve the smaller greed first
int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int cnt = 0;
    int i = 0;
    int j = 0;
    while (i < g.size() && j < s.size())
    {
        if (g[i] <= s[j])
        {
            cnt++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return cnt;
}