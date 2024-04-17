#include <bits/stdc++.h>
using namespace std;

/*Brute force
int getKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> sumStore;

    for (int i = 0; i < n; i++)
    {
        //	Stores the subarray sum.
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            sumStore.push_back(sum);
        }
    }

    //	Sort in non-increasing order.
    sort(sumStore.begin(), sumStore.end(), greater<int>());

    return sumStore[k - 1];
}
*/

/* optimal using heap*/

int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}