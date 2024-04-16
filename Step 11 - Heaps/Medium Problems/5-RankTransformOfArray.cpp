#include <bits/stdc++.h>
using namespace std;

// brute force

vector<int> arrayRankTransform(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        set<int> s;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                s.insert(arr[j]);
            }
        }
        ans.push_back(s.size() + 1);
    }
    return ans;
}

// using heap

vector<int> arrayRankTransform(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        return {};
    }
    vector<int> ans(n);
    // create a min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({arr[i], i});
    }

    // assign rank to first element of queue and pop it
    int rank = 1;
    int prev = pq.top().first;
    ans[pq.top().second] = rank;
    pq.pop();

    // for remaining elements
    while (!pq.empty())
    {
        if (pq.top().first > prev)
        {
            rank++;
            prev = pq.top().first;
        }
        ans[pq.top().second] = rank;
        pq.pop();
    }
    return ans;
}
