#include <bits/stdc++.h>
using namespace std;

// Brute Force
int numberOfSubstrings(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        vector<int> mpp(3, 0);
        for (int j = i; j < s.size(); j++)
        {
            mpp[s[j] - 'a'] = 1;
            if (mpp[0] == 1 && mpp[1] == 1 && mpp[2] == 1)
            {
                cnt++;
                /* //optimisation
                    cnt = cnt + (n - j);
                    break;
                */
            }
        }
    }
    return cnt;
}

// optimal

int numberOfSubstrings(string s)
{
    vector<int> mpp(3, -1); // keep tracks of last seen index of each character
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        mpp[s[i] - 'a'] = i;
        if (mpp[0] != -1 && mpp[1] != -1 && mpp[2] != -1)
        {
            cnt = cnt + (1 + min(mpp[0], min(mpp[1], mpp[2])));
        }
    }
    return cnt;
}