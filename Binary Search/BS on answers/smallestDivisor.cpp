#include <bits/stdc++.h>
using namespace std;
/*BruteForce
int smallestDivisor(vector<int> &arr, int limit)
{
    int n = arr.size();
    // Find the maximum element:
    int maxi = *max_element(arr.begin(), arr.end());

    // Find the smallest divisor:
    for (int d = 1; d <= maxi; d++)
    {
        // Find the summation result:
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)(arr[i]) / (double)(d));
        }
        if (sum <= limit)
            return d;
    }
    return -1;
}*/

/*binary optimal solution*/
int divide(vector<int> arr, int divisor)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += ceil((double)(arr[i]) / (double)(divisor));
    }
    return sum;
}
int smallestDivisor(vector<int> &arr, int limit)
{
    int n = arr.size();
    // Find the maximum element:
    int maxi = *max_element(arr.begin(), arr.end());

    int low = 1, high = maxi;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (divide(arr, mid) <= limit)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}
