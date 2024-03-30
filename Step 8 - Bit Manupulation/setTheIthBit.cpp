#include <bits/stdc++.h>
using namespace std;

int setBit(int n, int k)
{
    int leftshifted = 1 << k;
    int ans = (n | leftshifted);
    return ans;
}

int main()
{
    cout << setBit(9, 2);
    return 0;
}