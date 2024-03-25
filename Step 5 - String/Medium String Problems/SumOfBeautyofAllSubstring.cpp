#include <bits/stdc++.h>
using namespace std;
int beautySum(string s)
{
    int ans = 0;
    int n = s.length();
    for (int i = 0; i < s.length(); i++)
    {
        unordered_map<char, int> mpp;
        for (int j = i; j < s.length(); j++)
        {
            mpp[s[j]]++;
            int maxFreq = 0, minFreq = INT_MAX;
            for (auto it : mpp)
            {
                maxFreq = max(maxFreq, it.second);
                minFreq = min(minFreq, it.second);
            }
            ans += (maxFreq - minFreq);
        }
    }
    return ans;
}
int main()
{
    string a = "aabcbaa";

    return 0;
}