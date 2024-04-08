#include <bits/stdc++.h>
using namespace std;
// sum of subarray maximums - sum of subarray minimums = sum of subarray ranges
long long sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    stack<pair<int, int>> nle; // pair {element , count of element in subarray where its smallest element}
    stack<pair<int, int>> ple;
    vector<int> left(n, 0);  // for distance to prev less element
    vector<int> right(n, 0); // for distance to next less element

    for (int i = 0; i < arr.size(); i++)
    {
        int cnt = 1;
        // for previous less
        while (!ple.empty() && ple.top().first > arr[i])
        {
            cnt += ple.top().second;
            ple.pop();
        }
        ple.push({arr[i], cnt});
        left[i] = cnt;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int cnt = 1;
        // for next less
        while (!nle.empty() && nle.top().first >= arr[i])
        {
            cnt += nle.top().second;
            nle.pop();
        }
        nle.push({arr[i], cnt});
        right[i] = cnt;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans + arr[i] * (long long)(left[i] * right[i]);
    }
    return ans;
}

long long sumSubarrayMaxs(vector<int> &arr)
{
    int n = arr.size();
    stack<pair<int, int>> nge; // pair {element , count of element in subarray where its smallest element}
    stack<pair<int, int>> pge;
    vector<int> left(n, 0);  // for distance to prev greater element
    vector<int> right(n, 0); // for distance to next greater element

    for (int i = 0; i < arr.size(); i++)
    {
        int cnt = 1;
        // for previous less
        while (!pge.empty() && pge.top().first < arr[i])
        {
            cnt += pge.top().second;
            pge.pop();
        }
        pge.push({arr[i], cnt});
        left[i] = cnt;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int cnt = 1;
        // for next less
        while (!nge.empty() && nge.top().first <= arr[i])
        {
            cnt += nge.top().second;
            nge.pop();
        }
        nge.push({arr[i], cnt});
        right[i] = cnt;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans + arr[i] * (long long)(left[i] * right[i]);
    }
    return ans;
}

long long subArrayRanges(vector<int> &nums)
{
    return (sumSubarrayMaxs(nums) - sumSubarrayMins(nums));
}