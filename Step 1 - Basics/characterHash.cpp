#include <iostream>
using namespace std;
// index = char - 'a' for small char

int main()
{

    string s;
    cin >> s;
    int hash[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i] - 'a'] += 1;
    }

    int q;
    while (q--)
    {
        char c;
        cout << "enter Character : ";
        cin >> c;
        cout << "Count is : " << hash[c - 'a'] << endl;
    }

    return 0;
}