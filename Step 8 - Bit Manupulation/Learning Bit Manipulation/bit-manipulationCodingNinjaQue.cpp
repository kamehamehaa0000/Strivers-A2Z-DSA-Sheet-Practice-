#include <bits/stdc++.h>
using namespace std;
// 1 indexed

vector<int> bitManipulation(int n, int k)
{
    vector<int> ans;
    // chck the bit
    int leftShifted = 1 << k - 1;
    if ((n & leftShifted) != 0)
    {
        ans.push_back(1);
    }
    else
    {
        ans.push_back(0);
    }
    // set the bit
    int setted = n | leftShifted;
    ans.push_back(setted);

    // clear the bit
    int cleared = setted ^ leftShifted;
    ans.push_back(cleared);
    return ans;
}