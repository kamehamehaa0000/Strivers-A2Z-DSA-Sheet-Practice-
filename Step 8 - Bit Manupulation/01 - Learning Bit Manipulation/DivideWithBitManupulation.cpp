#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
    if (dividend == divisor)
    {
        return 1;
    }
    bool sign = true; //+ve
    if (dividend >= 0 && divisor < 0)
    {
        sign = false;
    }
    if (dividend <= 0 && divisor > 0)
    {
        sign = false;
    }
    long n = abs(dividend);
    long d = abs(divisor);
    divisor = abs(divisor);
    int ans = 0;
    while (n >= d)
    {
        int cnt = 0;
        while (n >= (d << (cnt + 1))) // d<<cnt+1 ==  d*2^cnt+1
        {
            cnt++;
        }
        ans += 1 << cnt; // 1 << cnt == 2^cnt
        n -= (d << cnt);
    }
    if (ans == (1 << 31) && sign)
    {
        return INT_MAX;
    }
    if (ans == (1 << 31) && !sign)
    {
        return INT_MIN;
    }
    return sign ? ans : -ans;
}