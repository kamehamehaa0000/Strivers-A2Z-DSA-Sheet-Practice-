#include <bits/stdc++.h>
using namespace std;

static bool cmp(vector<int> a, vector<int> b)
{
    return (a[2] > b[2]);
}
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), cmp);
    vector<int> temp(n + 1, -1);

    int count = 0;
    int profit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i][1]; j > 0; j--)
        {
            // if slot is available
            if (temp[j] == -1)
            {
                temp[j] = jobs[i][2];
                profit += jobs[i][2];
                count++;
                break;
            }
        }
    }

    return {count, profit};
}