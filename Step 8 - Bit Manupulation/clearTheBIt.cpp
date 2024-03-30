#include <bits/stdc++.h>
using namespace std;
// 0 indexed
// it is also the code for toggling the bit
int clearBit(int n, int k)
{
    int leftShifted = 1 << k;
    int cleared = n ^ leftShifted;
    return cleared;
}