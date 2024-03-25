#include <bits/stdc++.h>
using namespace std;

int recursive(string s, int sign, int i, long result)
{
    // base cases
    // if not a num or end of string
    if (i >= s.size() || s[i] < '0' || s[i] > '9')
    {
        return sign * result;
    }
    // if overflow
    if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10))
    {
        if (sign == 1)
        {
            return INT_MAX;
        }
        else
        {
            return INT_MIN;
        }
    }

    int num = s[i] - '0';
    result = recursive(s, sign, i + 1, (result * 10 + num));
    return result;
}

int myAtoi(string s)
{
    int i = 0, n = s.size(), sign = 1;
    // removing leading whitespaces
    while (i < n && s[i] == ' ')
    {
        ++i;
    }
    // looking for sign
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        sign = 1;
        i++;
    }
    // calling recursive function to convert string to int
    return recursive(s, sign, i, 0);
}

int main()
{
}
/*Explaination of overflow base conditions

    (result > INT_MAX / 10):This condition checks if multiplying the current result
    by 10 would exceed or equal INT_MAX. If so, returning INT_MAX prevents overflow.

    (result == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10):
    This condition checks if the result is equal to INT_MAX divided by 10.
    If it is, we need to check whether appending the next digit ((s[i] - '0'))
    would cause overflow. If so, again, returning INT_MAX prevents overflow.


*/