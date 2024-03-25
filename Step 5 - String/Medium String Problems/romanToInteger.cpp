#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> mpp; // symbol : value
    mpp['I'] = 1;
    mpp['V'] = 5;
    mpp['X'] = 10;
    mpp['L'] = 50;
    mpp['C'] = 100;
    mpp['D'] = 500;
    mpp['M'] = 1000;
    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (mpp[s[i]] < mpp[s[i + 1]])
        {
            ans -= mpp[s[i]]; // to handle IV IX XL XC CD CM
        }
        else
        {
            ans += mpp[s[i]];
        }
    }
    return ans;
}

string intToRoman(int num)
{
    // make sure to put value in the arrays/vector in descending order and symbol == value at a given index on both array
    vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string ans = "";

    for (int i = 0; i < value.size(); i++)
    {
        while (num >= value[i])
        {
            ans += symbol[i];
            num -= value[i];
        }
    }
    return ans;
    // NOTE: time complexity will O(1) cause loops are running for constant times
}

int main()
{
    string s = "MCMXCIV";
    int num = 1994;

    cout << romanToInt(s) << endl;
    cout << intToRoman(num);

    return 0;
}