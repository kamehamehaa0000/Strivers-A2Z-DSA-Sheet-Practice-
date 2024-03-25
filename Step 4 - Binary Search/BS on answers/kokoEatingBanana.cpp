#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE
int findMax(vector<int> &v)
{
    int maxi = INT_MIN;
    int n = v.size();
    // find the maximum:
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly)
{
    int totalH = 0;
    int n = v.size();
    // find total hours:
    for (int i = 0; i < n; i++)
    {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h)
{
    // Find the maximum number:
    int maxi = findMax(v);

    // Find the minimum value of k:
    for (int i = 1; i <= maxi; i++)
    {
        int reqTime = calculateTotalHours(v, i);
        if (reqTime <= h)
        {
            return i;
        }
    }

    // dummy return statement
    return maxi;
}
*/
/*binary search optimal solution*/
int findMax(vector<int> &arr)
{
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}
long long calculateTotalHours(vector<int> &arr, int hourly)
{
    long long totalHrs = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        totalHrs += ceil((double)(arr[i]) / (double)(hourly));
    }
    return totalHrs;
}
int minimumRateToEatBananas(vector<int> &arr, int hours)
{
    int low = 1;
    int high = findMax(arr);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        long long reqTime = calculateTotalHours(arr, mid);
        if (reqTime <= hours)
        {
            high = mid - 1;
        }
        else // (reqTime > hours)
        {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}
