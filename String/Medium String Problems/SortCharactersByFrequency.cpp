#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s)
{
    map<char, int> mpp;                      // char : count
    priority_queue<pair<int, char>> heapMax; // max heap using priority queue
    for (char c : s)
    {
        mpp[c]++; // count of char stored in map mpp
    }
    for (auto i : mpp)
    {
        heapMax.push({i.second, i.first}); // pushing {count :char} pair in queue to so they get sorted acc to max count
    }

    string ans = ""; // using extra string to store answer

    while (!heapMax.empty())
    {
        ans += string(heapMax.top().first, heapMax.top().second); // appending string(freq,char)
        heapMax.pop();                                            // removing the most freq char from top so we can insert next most occured char
    }

    return ans;
}

int main()
{
    string s = "tree";
    cout << frequencySort(s);
}