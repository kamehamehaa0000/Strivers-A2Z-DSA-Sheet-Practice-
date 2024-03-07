#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &arr, long long k)
{

    /*BruteForce
    int n = arr.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++)
    { // starting index
        for (int j = i; j < n; j++)
        { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            long long sum = 0;
            for (int K = i; K <= j; K++)
            {
                sum += arr[K];
            }

            if (sum == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
    */
    /*BruteForce but 0(n2) instead of O(n3)
    int n = arr.size(); // size of the array.
    int len = 0;
    for (int i = 0; i < n; i++)
    { // starting index
        long long sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
                len = max(len, j - i + 1);
        }
    }
    return len;*/

    /*better solution also for negatives zeros and positive
    int n = arr.size();
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
            maxLen = max(maxLen, i + 1);

        long long rem = sum - k;

        if (preSumMap.find(rem) != preSumMap.end())
        { // if the element is found before the end of the map
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
    */

    // optimal solution 2 pointer greedy approach
    int n = arr.size();
    int i = 0, j = 0; // 2 pointers
    long long sum = arr[0];
    int maxLen = 0;
    while (j < n)
    {
        // if sum > k, reduce the subarray from i
        // until sum becomes less or equal to k:
        while (i <= j && sum > k)
        {
            sum -= arr[i];
            i++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k)
        {
            maxLen = max(maxLen, j - i + 1);
        }

        // Move forward thw j pointer:
        j++;
        if (j < n)
            sum += arr[j];
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 1, 1, 1, 7};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}