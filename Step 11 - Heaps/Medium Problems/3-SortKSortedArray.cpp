#include <bits/stdc++.h>
using namespace std;
/*
A k-sorted array is one where each element is
at most k positions away from its sorted position.
*/
vector<int> nearlySorted(int arr[], int n, int k)
{
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0;
    while (i < n)
    {
        while (pq.size() > k)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        pq.push(arr[i]);
        i++;
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}