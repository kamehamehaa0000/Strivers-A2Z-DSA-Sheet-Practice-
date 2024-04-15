#include <bits/stdc++.h>
using namespace std;

// brute force
int findKthLargest(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

// using heap
int findKthLargest(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(nums[i]);
    }
    int elToPop = k - 1;
    while (elToPop > 0)
    {
        pq.pop();
        elToPop--;
    }
    return pq.top();
}