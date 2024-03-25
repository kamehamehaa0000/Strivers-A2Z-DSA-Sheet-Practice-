

#include <bits/stdc++.h>
using namespace std;
/*BruteForce
int subarraysWithXorK(vector<int> a, int k)
{
    int n = a.size();
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {

            // step 2:calculate XOR of all element in subarray [i to j]
            int xorr = 0;
            for (int K = i; K <= j; K++)
            {
                xorr = xorr ^ a[K];
            }

            // step 3:check XOR and count:
            if (xorr == k)
                cnt++;
        }
    }
    return cnt;
}
*/
/*better
int subarraysWithXorK(vector<int> a, int k)
{
    int n = a.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int xorr = 0;
        for (int j = i; j < n; j++)
        {
            xorr = xorr ^ a[j];
            if (xorr == k)
            {
                cnt++;
            }
        }
    }
    return cnt;
}*/
/*optimal
//is there a sub array ending at k having xor k
*/
int subarraysWithXorK(vector<int> a, int k)
{
    int n = a.size();
    int xr = 0;
    map<int, int> mpp; //(xor:count)
    mpp[xr] = 1;       // setting the initial value of 0.- {0,1}
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        // prefix XOR till index i:
        xr = xr ^ a[i];
        // By formula: x = xr^k:
        int x = xr ^ k;

        // add occurance of xr^k to the count
        cnt += mpp[x];

        // Insert the prefix xor till index i into the map:
        mpp[xr]++;
    }
    return cnt;
}
int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: " << ans << "\n";
    return 0;
}