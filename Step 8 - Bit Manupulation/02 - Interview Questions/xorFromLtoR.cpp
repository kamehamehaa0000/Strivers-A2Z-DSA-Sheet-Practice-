#include <bits/stdc++.h>
using namespace std;

// Brute force but gives TLE
int findXOR(int L, int R)
{
    int ans = 0;
    for (int i = L; i <= R; i++)
    {
        ans = ans ^ i;
    }
    return ans;
}

// optimal
int helper(int n)
{
    if (n % 4 == 1)
    {
        return 1;
    }
    else if (n % 4 == 2)
    {
        return n + 1;
    }
    else if (n % 4 == 3)
    {
        return 0;
    }

    else // (n % 4 == 0)
    {
        return n;
    }
}
int findXOR(int L, int R)
{
    return helper(L - 1) ^ helper(R);
}