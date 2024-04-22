#include <bits/stdc++.h>
using namespace std;
// both are greedy solution but implementation is different

//  code1

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    if (intervals.empty())
    {
        return 0;
    }
    // Sort intervals based on their end points
    sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b)
         { return a[1] < b[1]; });

    int ans = 0;
    int end = intervals[0][1]; // End point of the first interval

    for (int i = 1; i < intervals.size(); ++i)
    {
        // If there's an overlap, increment ans
        if (intervals[i][0] < end)
        {
            ++ans;
        }
        else
        {
            // Update the end point
            end = intervals[i][1];
        }
    }

    return ans;
}

// code 2

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    int i = 0;
    int j = 1;
    int ans = 0;
    while (j < intervals.size())
    {
        int iend = intervals[i][1];
        int jstart = intervals[j][0];
        int jend = intervals[j][1];

        // if not overlaping
        if (iend <= jstart)
        {
            i = j;
            j++;
        }
        // if overlaping
        else if (iend <= jend)
        {
            ans++;
            j++;
        }
        // if overlapping
        else if (iend > jend)
        {
            ans++;
            i = j;
            j++;
        }
    }
    return ans;
}