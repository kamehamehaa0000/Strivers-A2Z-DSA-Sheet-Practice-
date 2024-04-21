#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> arr(n, 1); // stored candy;
    // calculate for left neighbours
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            arr[i] = arr[i - 1] + 1;
        }
    }
    // calculate for right neighbours
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            arr[i] = max(arr[i], arr[i + 1] + 1);
        }
    }
    // return sum of both left and right
    int ans = 0;
    for (int i : arr)
    {
        ans += i;
    }
    return ans;
}