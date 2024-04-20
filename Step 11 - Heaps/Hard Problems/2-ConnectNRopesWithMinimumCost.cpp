#include <bits/stdc++.h>
using namespace std;

int minCost(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    int ans = 0;
    while (pq.size() > 1)
    {
        int cost = 0;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        cost = first + second;
        ans += cost;
        pq.push(cost);
    }
    return ans;
}