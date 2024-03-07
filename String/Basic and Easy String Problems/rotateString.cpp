#include <bits/stdc++.h>
using namespace std;

// bool rotateString(string s, string goal)
// {
//     if (s.size() != goal.size())
//     {
//         return false;
//     }
//     string ans = s + s;

//     if (ans.find(goal) == -1)
//     {
//         return false;
//     }
//     else
//         return true;
// }
// queue implementaion
bool rotateString(string s, string goal)
{
    if (s == goal)
    {
        return true;
    }
    queue<char> q1, q2;
    for (int i = 0; i < s.size(); i++)
    {
        q1.push(s[i]);
        q2.push(goal[i]);
    }

    int k = s.size() - 1;
    while (k > 0)
    {
        q1.push(q1.front());
        q1.pop();

        if (q1 == q2)
        {
            return true;
        }
        k--;
    }
    return false;
}

int main()
{
    string s = "abcde";
    string t = "cdeab";
    cout << rotateString(s, t); // 123 will be the output
}
