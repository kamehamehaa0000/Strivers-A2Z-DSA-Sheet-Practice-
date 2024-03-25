#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num)
{
    for (int i = num.size() - 1; i >= 0; i--)
    {
        if (num[i] % 2 == 1)
        {
            return num.substr(0, i + 1);
        }
    }
    return "";
}
int main()
{
    string s = "1234";
    cout << largestOddNumber(s); // 123 will be the output
}