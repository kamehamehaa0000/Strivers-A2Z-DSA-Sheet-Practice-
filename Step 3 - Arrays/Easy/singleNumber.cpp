#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int> &arr)
{

    /* brute
      int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int num = arr[i];
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == num)
            {
                count++;
            }
        }
        if (count == 1)
        {
            return num;
        }
    }
    */
    /*
    better-using hashing
    int n = arr.size();

    // Declare the hashmap.
    // And hash the given array:
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // Find the single element and return the answer:
    for (auto it : mpp)
    {
        if (it.second == 1)
            return it.first;
    }

    // This line will never execute
    // if the array contains a single element.
    return -1;*/

    /*optimal
    using xor
    Assume the given array is: [4,1,2,1,2]
    XOR of all elements = 4^1^2^1^2
      = 4 ^ (1^1) ^ (2^2)
      = 4 ^ 0 ^ 0 = 4^0 = 4
    Hence, 4 is the single element in the array.
    */

    int ans = 0;
    for (auto x : arr)
        ans ^= x;
    return ans;
}
int main()
{

    vector<int> arr = {4, 4, 2, 1, 2};
    cout << singleNumber(arr);
    return 0;
}