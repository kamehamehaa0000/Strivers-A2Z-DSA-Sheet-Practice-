#include <bits/stdc++.h>
using namespace std;

string covertToBinary(int n)
{
    string res = "";
    while (n != 1)
    {
        if (n % 2 == 1)
        {
            res = res + '1';
        }
        else
        {
            res = res + '0';
        }
        n = n / 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int covertToDecimal(string x)
{
    int result = 0;
    int len = x.size();
    int p2 = 1;
    for (int i = len - 1; i >= 0; i--)
    {

        if (x[i] == '1')
        {
            result = result + p2;
        }
        p2 = p2 * 2;
        // if (x[i] == '0') do nothing
    }
    return result;
}