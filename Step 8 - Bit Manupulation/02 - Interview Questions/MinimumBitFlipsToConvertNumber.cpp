#include <bits/stdc++.h>
using namespace std;
/* solution 1 - O(31)*/
int minBitFlips(int start, int goal)
{
    int ans = start ^ goal; // will turn the bits that need to be flipped to set bits
    int cnt = 0;
    // count the no. of set bit in ans and that will be your ans
    for (int i = 0; i < 31; i++) // 0 to 31 cause we are only dealing with integers
    {
        if (ans & (1 << i))
        {
            cnt += 1;
        }
    }
    return cnt;
}

/*optimised solution - O(log2(ans))*/
int minBitFlips(int start, int goal)
{
    int ans = start ^ goal; // will turn the bits that need to be flipped to set bits
    int cnt = 0;
    // count the no. of set bit in ans and that will be your ans
    while (ans != 0)
    {
        cnt = cnt + (ans % 2);
        ans = ans / 2;
    }
    return cnt;
}