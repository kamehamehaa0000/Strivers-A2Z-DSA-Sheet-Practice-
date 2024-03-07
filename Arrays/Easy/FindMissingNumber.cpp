#include <bits/stdc++.h>
using namespace std;
int findMissing(int arr[], int n)
{
    /* brute force


    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {

            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return i;
    }
     */
    /*Better solution using hashing


    int hash[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (hash[i] == 0)
            return i;
    }
    */

    /*
        // Second Optimal  using XOR - XOR of two same no. is 0 and 0 XOR any number is number it self
        int xor1 = 0, xor2 = 0;

        for (int i = 0; i < n - 1; i++)
        {
            xor2 = xor2 ^ arr[i];  // XOR of array elements
            xor1 = xor1 ^ (i + 1); // XOR up to [1...N-1]
        }
        xor1 = xor1 ^ n; // XOR up to [1...N]

        return (xor1 ^ xor2); // the missing number*/

    // Optimal solution
    // first optimal solution - SUM and sum of n no. = n(n+1)/2
    long Nsum = (n * (n + 1)) / 2;
    long arrSum = 0;
    for (int i = 0; i < n; i++)
    {
        arrSum += arr[i];
    }
    return (Nsum - arrSum);
}
int main()
{
    int n = 9;
    int arr[n] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << findMissing(arr, n);
    return 0;
}