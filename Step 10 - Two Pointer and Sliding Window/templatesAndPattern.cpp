#include <bits/stdc++.h>
using namespace std;

// Pattern1 -  when its a constant window
// example -
int maxsumOfSubArrayOfKsize(vector<int> &arr, int k)
{
    int l = 0, r = k - 1;
    int sum = 0;
    int maxSum = 0;
    // find sum of initial window
    for (int i = l; i <= r; i++)
    {
        sum += arr[i];
    }
    maxSum = max(sum, maxSum);
    // move window
    while (r < (arr.size() - 1))
    {
        sum = sum - arr[l];
        l++;
        r++;
        sum = sum + arr[r];
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}

// Pattern 2 - longest subarray/substring where <condition>
// example - len of longest subarray with sum <= k
int longestSubrayLen(vector<int> &arr, int k)
{
    // start with window size 1
    int l = 0;
    int r = 0;
    int sum = arr[0];
    int maxLen = 0;
    while (r < arr.size())
    {
        sum = sum + arr[r];
        if (sum > k)
        {
            sum = sum - arr[l];
            l++;
        }
        if (sum <= k)
        {
            maxLen = max(maxLen, (r - l + 1));
            r++;
        }
    }
    return maxLen;
}

// Pattern 3 - number of subarray with <condition> usually with constant condition
// example - no. of subarrays with sum = k
// no. of subarray where sum <= k ----1
// no. of subarray where sum <= k-1 -----2
// ans = 1-2;

// pattern 4 - finding shortest / minimum window/len with <condition>
// take l and r and if window turnsout the valid window
// shrink it and check if its valid till you find valid minimum window

int main()
{
    vector<int> arr = {-1, 2, 3, 3, 4, 5, -1};
    cout << maxsumOfSubArrayOfKsize(arr, 4) << endl;
    vector<int> brr = {2, 5, 2, 1, 10, 10};
    cout << longestSubrayLen(brr, 14);
}