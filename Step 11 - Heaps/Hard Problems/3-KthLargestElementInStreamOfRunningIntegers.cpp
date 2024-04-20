#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
public:
    // using min heap will be better than maxheap cause max is same as using sorting which is nlogn but we want nlogk
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;

    KthLargest(int k, vector<int> &nums)
    {
        size = k;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > size)
        {
            pq.pop();
        }
        return pq.top();
    }
};