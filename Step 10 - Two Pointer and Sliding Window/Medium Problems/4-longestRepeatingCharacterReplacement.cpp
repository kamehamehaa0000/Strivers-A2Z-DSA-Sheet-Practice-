#include <bits/stdc++.h>
using namespace std;

// brute force
int characterReplacement(string s, int k)
{
    int n = s.size();
    int maxLen = 0;
    // changes =  len-maxfreq
    for (int i = 0; i < n; i++)
    {
        vector<int> mpp(26, 0); // stores freq
        int maxFreq = 0;
        for (int j = i; j < n; j++)
        {
            mpp[s[j] - 'A']++;
            maxFreq = max(maxFreq, mpp[s[j] - 'A']);
            int changes = (j - i + 1) - maxFreq;
            if (changes <= k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }
    return maxLen;
}

// optimal
int characterReplacement(string s, int k)
{
    int n = s.size();
    int maxFreq = 0;
    int maxLen = 0;
    vector<int> mpp(26, 0); // stores freq
    int l = 0;
    int r = 0;
    while (r < n)
    {
        mpp[s[r] - 'A']++;
        maxFreq = max(maxFreq, mpp[s[r] - 'A']);
        int changes = (r - l + 1) - maxFreq;
        if (changes <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        else //(changes > k)
        {
            mpp[s[l] - 'A']--;
            l++;
        }
        r++;
    }
    return maxLen;
}
