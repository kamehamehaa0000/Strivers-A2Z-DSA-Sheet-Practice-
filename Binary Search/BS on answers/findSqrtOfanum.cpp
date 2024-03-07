#include <bits/stdc++.h>
using namespace std;
/*bruteforce
int floorSqrt(int n)
{
    int ans = 0;
    // linear search on the answer space:
    for (long long i = 1; i <= n; i++)
    {
        long long val = i * i;
        if (val <= n * 1ll)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    return ans;
}
*/
int floorSqrt(int n)
{
    int low = 1;
    int high = n;
    int ans = 0;

    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (mid * mid == n)
        {
            return mid;
        }
        if (mid * mid < n)
        {
            ans = mid;
            low = mid + 1;
        }
        else //(mid * mid > n)
        {
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n = 17;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}
