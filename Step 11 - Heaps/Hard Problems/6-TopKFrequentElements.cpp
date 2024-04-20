#include <bits/stdc++.h>
using namespace std;

// using priority queue

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mpp; // num:freq
    for (int num : nums)
    {
        mpp[num]++;
    }
    vector<int> ans;
    priority_queue<pair<int, int>> pq; // pair{freq:num}
    for (auto i : mpp)
    {
        pq.push({i.second, i.first});
    }
    while (k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}
