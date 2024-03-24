#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        n = abs(n);
        x = 1 / x;
    }
    if (n % 2 == 0) // even
    {
        return (myPow(x * x, n / 2));
    }
    else // odd
    {
        return x * myPow(x, n - 1);
    }
}
// when n is even - x*x and n/2
// when n is odd - ans = ans * ans(with power n-1)
// when negative n => a^-n = (1/a)^n
