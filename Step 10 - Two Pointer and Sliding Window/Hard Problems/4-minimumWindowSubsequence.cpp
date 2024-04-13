#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    int start = -1;
    int minLen = INT_MAX;
    int n = s.size();
    int m = t.size();

    for (int i = 0; i < n; i++)
    {
        // Check if the current character in s matches the first character of t
        if (s[i] == t[0])
        {
            int sPtr = i;
            int tPtr = 0;
            // Traverse both strings to find the minimum window
            while (sPtr < n && tPtr < m)
            {
                if (s[sPtr] == t[tPtr])
                {
                    tPtr++;
                }
                sPtr++;
            }
            // If all characters of t are found in s
            if (tPtr >= m)
            {
                if (sPtr - i < minLen)
                {
                    start = i;
                    minLen = sPtr - i;
                }
            }
        }
    }
    // If no window is found
    if (start == -1)
    {
        return "";
    }
    return s.substr(start, minLen);
}