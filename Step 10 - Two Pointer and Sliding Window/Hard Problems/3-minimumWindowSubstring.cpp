#include <bits/stdc++.h>
using namespace std;

// optimal solution
string minWindow(string s, string t)
{
    vector<int> hashmpp(256, 0);
    int minLen = INT_MAX;
    int sIndex = -1;

    for (int j = 0; j < t.size(); j++)
    {
        hashmpp[t[j]]++;
    }

    int cnt = 0;
    int left = 0;

    for (int right = 0; right < s.size(); right++)
    {
        if (hashmpp[s[right]] > 0)
        {
            cnt++;
        }
        hashmpp[s[right]]--;

        while (cnt == t.size())
        {
            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                sIndex = left;
            }
            hashmpp[s[left]]++;
            if (hashmpp[s[left]] > 0)
            {
                cnt--;
            }
            left++;
        }
    }

    return sIndex == -1 ? "" : s.substr(sIndex, minLen);
}
