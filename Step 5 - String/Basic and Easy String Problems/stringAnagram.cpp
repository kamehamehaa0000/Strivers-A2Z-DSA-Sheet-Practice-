#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    int freqtable[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        freqtable[s[i]]++;
    }
    int freq[256] = {0};
    for (int i = 0; i < t.size(); i++)
    {
        freq[t[i]]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (freqtable[i] != freq[i])
        {
            return false;
        }
    };

    return true;
}
int main()
{
    cout << isAnagram("cat", "tac");
    return 0;
}
