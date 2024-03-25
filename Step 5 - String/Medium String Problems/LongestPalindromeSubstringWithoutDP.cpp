#include <bits/stdc++.h>
using namespace std;
/*Brute Force
bool isPalindrome(string str)
{
    int left = 0;
    int right = str.length() - 1;
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false;
        }
        ++left;
        --right;
    }
}

string longestPalindrome(string s)
{
    if (s.length() <= 1)
    {
        return s;
    }
    int maxLen = 1;
    string maxStr = s.substr(0, 1);
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + maxLen; j <= s.length(); j++)
        {
            if (j - i > maxLen && isPalindrome(s.substr(i, j - i)))
            {
                maxLen = j - i;
                maxStr = s.substr(i, j - i);
            }
        }
    }

    return maxStr;
}
*/
// expand from center approach
/*
string expandFromCenter(int left, int right, string str)
{
    while (left >= 0 && right < str.length() && str[left] == str[right])
    {
        left--;
        right++;
    }
    return str.substr(left + 1, right - left - 1);
}
string longestPalindrome(string s)
{
    if (s.length() <= 1)
    {
        return s;
    }

    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        string odd = expandFromCenter(i, i, s);
        string even = expandFromCenter(i, i + 1, s);
        if (odd.length() > ans.length())
        {
            ans = odd;
        }
        if (even.length() > ans.length())
        {
            ans = even;
        }
    }
    return ans;
}*/

// alternate code for above approach
string longestPalindrome(string s)
{
    int left = 0;
    int right = 0;
    int start = 0;
    int maxLen = 0;

    int i = 0;
    while (i < s.size())
    {
        left = i;
        right = i;

        while (right < s.size() - 1 && s[right] == s[right + 1]) // for even string
        {
            right++;
        }

        i = right + 1;

        while (left > 0 && right < s.size() - 1 && s[left - 1] == s[right + 1]) // for odd string
        {
            left--;
            right++;
        }

        int length = right - left + 1;
        if (length > maxLen)
        {
            start = left;
            maxLen = length;
        }
    }

    return s.substr(start, maxLen);
}

int main()
{
    string s = "babad";
    cout << longestPalindrome(s);

    return 0;
}
