#include <bits/stdc++.h>
using namespace std;
// Given an integer n, return the number of prime numbers
// that are strictly less than n.

int countPrimes(int n)
{
    int cnt = 0;
    vector<int> prime(n + 1, 1); // assuming every no. as prime
    for (int i = 2; i < n; i++)
    {
        if (prime[i] == 1)
        {
            cnt++;
            for (int j = i * 2; i < n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    return cnt;
}