#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int n = intervals.size();
    if (n == 0)
    {
        return {newInterval};
    }

    vector<vector<int>> res;
    int l = 0;

    // if end of interval < start of newInterval i.e if current interval is not overlapping
    while (l < n && intervals[l][1] < newInterval[0])
    {
        res.push_back(intervals[l]);
        l++;
    }
    // if start of interval <= end of newInterval i.e overlapping then update new interval
    while (l < n && intervals[l][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[l][0]);
        newInterval[1] = max(newInterval[1], intervals[l][1]);
        l++;
    }
    res.push_back(newInterval);

    // push remaining intervals to the ans
    while (l < n)
    {
        res.push_back(intervals[l]);
        l++;
    }

    return res;
}