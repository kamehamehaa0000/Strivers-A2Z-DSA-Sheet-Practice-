#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
long power(long x, long n)
{
    if (n == 0)
    {
        return 1;
    }
    long temp = power(x, n / 2);
    if (n % 2 == 0)
    {
        return (temp * temp) % mod;
    }
    else //(n%2==1)
    {
        return ((x % mod) * temp * temp) % mod;
    }
}

int countGoodNumbers(long long n)
{
    long evenPlaces = (n + 1) / 2;
    long oddPlaces = n / 2;
    long long a = power(5, evenPlaces);
    long long b = power(4, oddPlaces);
    return (int)((a * b) % mod); // using permutation and combination
}
