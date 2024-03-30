#include <bits/stdc++.h>
using namespace std;
// 0 indexed //do k-1 for 1 indexed
//  using left shift
bool isSet(int n, int k)
{
    int leftShifted = 1 << k;
    if ((n & leftShifted) != 0)
    {
        return true;
    }
    return false;
}
// using right shift
bool isSet2(int n, int k)
{
    int rightShifted = n >> k;
    if ((rightShifted & 1) == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}