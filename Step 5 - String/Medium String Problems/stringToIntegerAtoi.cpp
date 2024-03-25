#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    long ans = 0;
    int sign = 1;
    int i = 0;
    // removing white Spaces
    while (s[i] == ' ' && i < s.length())
    {
        i++;
    }
    // checking for sign
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }
    // iterate through trimmed string
    while (i < s.length())
    {
        if (s[i] >= '0' && s[i] <= '9') // check for digit
        {
            ans = ans * 10 + (s[i] - '0');
            // check for overflow
            if (ans > INT_MAX && sign == -1)
            {
                return INT_MIN;
            }
            else if (ans > INT_MAX && sign == 1)
            {
                return INT_MAX;
            }
            i++;
        }
        else // if not digit return ans
        {
            return ans * sign;
        }
    }

    return (ans * sign);
}
int main()
{
    string s = "41";
    cout << myAtoi(s);
    return 0;
}