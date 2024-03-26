#include <bits/stdc++.h>
using namespace std;

/* // brute force Gives TLE

void helper(string a, int n, int i, string output, unordered_map<string, int> &mpp)
{
    if (i == n)
    {
        mpp[output] += 1;
        return;
    }
    // exclude
    helper(a, n, i + 1, output, mpp);
    // include
    output.push_back(a[i]);
    helper(a, n, i + 1, output, mpp);
}
string moreSubsequence(int n, int m, string a, string b)
{
    unordered_map<string, int> mpp1;
    unordered_map<string, int> mpp2;

    vector<string> res;
    string output1 = "";
    helper(a, n, 0, output1, mpp1);
    helper(b, m, 0, output1, mpp2);
    if (mpp1.size() == mpp2.size())
    {
        return a;
    }
    if (mpp1.size() > mpp2.size())
    {
        return a;
    }
    else
    {
        return b;
    }
}

*/
/* Optimal but no recursion */
int func(string s, int n)
{
    int count = 1;
    unordered_map<char, int> mpp;
    // Calculating number of distinct subsequences.
    for (int i = 0; i < n; i++)
    {
        if (mpp[s[i]] == 0)
        {
            mpp[s[i]] = count;
            count *= 2; // this accounts for both including and excluding the current character
        }
        else
        {
            int temp = mpp[s[i]];
            mpp[s[i]] = count;
            count *= 2;
            count -= temp; // eliminates the duplicate subsequences that result from including the current character.
        }
    }
    return count;
}

string moreSubsequence(int n, int m, string a, string b)
{
    if (func(a, n) >= func(b, m))
    {
        return a;
    }
    else
    {
        return b;
    }
}
