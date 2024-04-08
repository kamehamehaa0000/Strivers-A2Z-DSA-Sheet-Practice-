#include <bits/stdc++.h>
using namespace std;
/*optimal*/

int sumSubarrayMins(vector<int> &arr)
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

    int ans = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        ans = (ans + arr[i] * (long long)(left[i] * right[i]) % mod) % mod;
    }
    return ans;
}
