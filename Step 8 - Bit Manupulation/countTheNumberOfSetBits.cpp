#include <bits/stdc++.h>
using namespace std;

int countSetBit(int n)
{
    int cnt = 0;
    while (n != 1)
    {
        if (n % 2 == 1)
        {
            cnt++;
        }
        n = n / 2;
    }
    cnt++; // increase cnt cause loop will not run for last 1;

    return cnt;
}
/// code ninja problem but gives TLE cause we are finding the cnt for n natural number
int countSetBits(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int num = i; // Use the current value of i
        int cnt = 0;
        while (num != 0)
        {
            if (num % 2 == 1)
            {
                cnt++;
            }
            num = num / 2;
        }
        sum += cnt;
    }
    return sum;
}
/// code ninja problem but gives TLE cause we are finding the cnt for n natural number

int countSetBits(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int num = i; // Use the current value of i
        int cnt = 0;
        while (num != 0)
        {
            num = num & (num - 1);
            cnt++;
        }
        sum += cnt;
    }
    return sum;
}

/// code ninja problem optimal solution

int countSetBits(int N)
{

    int d = 2, ans = 0, x = N;
    while (x)
    {

        // Using the Mathematical formula explained in the Approach.
        ans += ((N + 1) / d) * (d / 2) + max((N + 1) % d - d / 2, 0);

        // Window size double every time we shift to the next left bit.
        d *= 2;
        x /= 2;
    }
    return ans;
}
/*Explaination
Considering the range from 1 to N is equivalent to the range from 0 to N, we can analyze the count of set bits by examining each bit position individually.
When counting the set bits from 0 to N in the binary representation of numbers, we can observe a repeating pattern at the units place. The pattern consists of a window size of 2, with the sequence "01" repeating. At the next place, the window size doubles to 4, and the pattern becomes "0011". This pattern continues for each subsequent bit position.
0000 -> 0
0001 -> 1
0010 -> 2
0011 -> 3
0100 -> 4
0101 -> 5
0110 -> 6
0111 -> 7
1000 -> 8
1001 -> 9
1010 -> 10
To calculate the count of set bits for the complete repetitions of the window, we multiply the number of complete repetitions, which is (N+1)/d, by the count of set bits in each repetition, which is d/2. This gives us ((N+1)/d)*(d/2) set bits from the complete repetitions.

For the remaining part, which is (N+1)%d, we know that the first d/2 bits are always zeros. To obtain the count of set bits in the remaining part, we subtract d/2 from (N+1)%d. However, if (N+1)%d is less than d/2, it results in a negative number. To avoid this, we take the maximum of ((N+1)%d - d/2) and 0, ensuring a non-negative count.

By applying this calculation process from the least significant bit to the most significant bit, starting with a window size of 2 and doubling it at each step, we can efficiently count the set bits in the binary representation of numbers from 0 to N.*/