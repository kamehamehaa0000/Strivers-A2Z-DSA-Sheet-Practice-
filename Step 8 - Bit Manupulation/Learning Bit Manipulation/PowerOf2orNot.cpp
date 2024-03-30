#include <bits/stdc++.h>
using namespace std;
// will only have one set bit if its a power of 2
bool isPowerOfTwo(int n)
{
    if (n <= 0)
    {
        return false;
    }
    return ((n & (n - 1)) == 0);
}