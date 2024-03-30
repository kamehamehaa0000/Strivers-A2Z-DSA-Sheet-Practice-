#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Right Shift (>>) - Removes least significant bit or rightmost bit.
    cout << (13 >> 1) << endl;  // 6
    cout << (-13 >> 1) << endl; // -7

    // Left Shift (<<) - Shifts most significant bit or leftmost bit.
    cout << (13 << 1) << endl;  // 26
    cout << (-13 << 1) << endl; // -26

    // Logical AND (&&) - If all operands are true, result is true; otherwise false.
    cout << (1 & 0) << endl; // 0
    cout << (13 & 13) << endl;

    // Bitwise XOR (^) - True if operands have different boolean values, false otherwise.
    cout << (10 ^ 6) << endl; // 12

    // Bitwise NOT (~) - Inverts each bit of the operand.
    cout << (~-6) << endl; // 5

    return 0;
}

// OR (|) - If at least one operand is true, result is true; otherwise false.

/*
    Formula to find right shift => x >> k = x / (2^k)
    Formula to find left shift => x << k = x * (2^k)
*/
