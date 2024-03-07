#include <bits/stdc++.h>
using namespace std;
// aproach 1
// bool isIsomorphic(string s, string t)
// {
//     unordered_map<char, char> mpp1, mpp2;
//     int i = 0;
//     int j = 0;

//     while (i < s.size() && j < t.size())
//     {
//         if (!mpp1.count(s[i]) && !mpp2.count(t[i]))
//         {
//             mpp1[s[i]] = t[j];
//             mpp2[t[j]] = s[i];
//         }
//         if (mpp1[s[i]] != t[j] or mpp2[t[j]] != s[i])
//         {
//             return false;
//         }
//         i++;
//         j++;
//     }
//     return true;
// }
// approach 2
bool isIsomorphic(string s, string t)
{
    char mpp1[128] = {0};
    char mpp2[128] = {0};
    for (int i = 0; i < s.size(); ++i)
    {
        if (mpp1[s[i]] != mpp2[t[i]])
            return false;
        mpp1[s[i]] = i + 1;
        mpp2[t[i]] = i + 1;
    }
    return true;
}

int main()
{
    string s = "ford";
    string t = "bord";
    cout << isIsomorphic(s, t); // 123 will be the output
}