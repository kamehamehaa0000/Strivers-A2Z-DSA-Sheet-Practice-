#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());
    string s1 = strs[0];
    string s2 = strs[strs.size() - 1];
    int index = 0;
    while (index < s1.size() && index < s2.size())
    {
        if (s1[index] == s2[index])
        {
            index++;
        }
        else
        {
            break;
        }
    }

    return s1.substr(0, index);
}
int main()
{

    vector<string> s = {"flower",
                        "flow",
                        "flight"};
    cout << longestCommonPrefix(s); // output should be fl

    return 0;
}