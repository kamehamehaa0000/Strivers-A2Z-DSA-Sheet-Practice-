#include <bits/stdc++.h>
using namespace std;

int clearLastSetBit(int n)
{
    return (n & n - 1);
}
int setLastUnsetBit(int n)
{
    if ((n & n + 1) == 0)
    {
        return n;
    }
    return (n | n + 1);
}
int main()
{
    cout << clearLastSetBit(84);
}