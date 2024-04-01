#include <bits/stdc++.h>
using namespace std;

vector<int> twoOddNum(vector<int> arr)
{
    int xr = 0;
    for (int i = 0; i < arr.size(); i++)
    {

        xr ^= arr[i];
    }
    // rightmost bit turned one after xor will be
    int rightmost = (xr & xr - 1) ^ xr;
    // if num has rightmost as 1 put in bucket 1 else in bucket 2;
    int b1 = 0;
    int b2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (rightmost & arr[i])
        {
            b1 ^= arr[i];
        }
        else
        {
            b2 ^= arr[i];
        }
    }
    if (b1 > b2)
    {
        return {b1, b2};
    }
    return {b2, b1};
}