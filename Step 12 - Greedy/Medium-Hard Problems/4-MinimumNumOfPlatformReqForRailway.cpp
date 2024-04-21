#include <bits/stdc++.h>
using namespace std;
/*
// brute force
int calculateMinPatforms(int arr[], int dep[], int n)
{
    int ans = 1;
    for (int i = 0; i <= n - 1; i++)
    {
        int count = 1;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                (arr[j] >= arr[i] && arr[j] <= dep[i]))
            {
                count++;
            }
        }
        ans = max(ans, count);
    }
    return ans;
}
*/

// optimal
int calculateMinPatforms(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int ans = 1;
    int count = 1;
    int i = 1; // pointing to arrival
    int j = 0; // pointing to departure

    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            // one more platform needed
            count++;
            i++;
        }
        else
        {
            // one platform can be reduced
            count--;
            j++;
        }
        ans = max(ans, count);
    }
    return ans;
}