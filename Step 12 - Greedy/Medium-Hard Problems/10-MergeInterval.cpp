#include <bits/stdc++.h>
using namespace std;

/*Brute Force
vector<vector<int>> merge(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        // Skip all the merged intervals:
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }
        // check the rest of the intervals:
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}
*/

/* optimal */

vector<vector<int>> merge(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        // if the current interval does not lie in the last interval
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        // if the current interval lies in the last interval:
        else // if arr[i][1] > ans.back()[1] i.e if overlapping
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}