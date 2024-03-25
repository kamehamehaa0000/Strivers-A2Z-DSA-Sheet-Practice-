
#include <bits/stdc++.h>
using namespace std;
/*bruteforce linear search
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = -1, last = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            if (first == -1)
                first = i;
            last = i;
        }
    }
    return {first, last};
}*/
/*better
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{

    int lb = n;  // lowerbound or first occurrance //initial value out of arr
    int ub = -1; // upperbound or last occurrance+1;
    lb = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
    ub = upper_bound(arr.begin(), arr.end(), k) - arr.begin();
    if (lb == n || arr[lb] != k)
    {
        return {-1, -1};
    }
    return {lb, ub - 1};
}*/
/*without lower bound and upperbound concept*/
int firstOccurrence(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k)
        {
            first = mid;
            // look for smaller index on the left
            high = mid - 1;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1; // look on the right
        }
        else
        {
            high = mid - 1; // look on the left
        }
    }
    return first;
}

int lastOccurrence(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k)
        {
            last = mid;
            // look for larger index on the right
            low = mid + 1;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1; // look on the right
        }
        else
        {
            high = mid - 1; // look on the left
        }
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = firstOccurrence(arr, n, k);
    if (first == -1)
        return {-1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, k = 8;
    pair<int, int> ans = firstAndLastPosition(arr, n, k);
    cout << "The first and last positions are: "
         << ans.first << " " << ans.second << "\n";
    return 0;
}
