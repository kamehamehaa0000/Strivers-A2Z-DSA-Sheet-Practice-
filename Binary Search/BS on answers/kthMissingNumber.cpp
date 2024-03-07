#include <bits/stdc++.h>
using namespace std;
/*Brute force
int missingK(vector<int> vec, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (vec[i] <= k)
            k++; // shifting k
        else
            break;
    }
    return k;
}*/
/*optimal*/
int missingK(vector<int> vec, int n, int k)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1); // missing = value - (index+1)
        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return k + high + 1; // or low + k since low=high+1

    /*formula derivation
    ans = arr[high] +( k - missing) or arr[high] + more
    and more = k - missing
    missing = arr[high] -( high +1)
    therefore ans = arr[high] + k - (arr[high] - (high+1))
            = k+high+1; or (high+1) +k or low+k

    */
}
int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}
