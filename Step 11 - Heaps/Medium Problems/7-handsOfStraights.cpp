#include <bits/stdc++.h>
using namespace std;
// code 1

bool isNStraightHand(vector<int> &hand, int groupSize)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> a;
    for (auto it : hand)
    {
        pq.push(it);
    }
    int temp = 1;
    int i = 0;
    while (i < hand.size())
    {
        int prev = pq.top();
        pq.pop();
        while (temp < groupSize && !pq.empty())
        {
            if (pq.top() - 1 == prev)
            {
                prev = pq.top();
                pq.pop();
                temp++;
            }
            else if (pq.top() == prev)
            {
                a.push_back(pq.top());
                pq.pop();
            }
            else
            {
                return false;
            }
        }
        if (temp != groupSize)
        {
            return false;
        }
        for (int i = 0; i < a.size(); i++)
        {
            pq.push(a[i]);
        }
        a.resize(0);
        i = i + temp;
        temp = 1;
    }
    return true;
}

// code 2
bool isNStraightHand(vector<int> &hand, int gs)
{
    int n = hand.size();
    if (n % gs)
    {
        return false;
    }
    map<int, int> mp;
    for (auto x : hand)
    {
        mp[x]++;
    }
    priority_queue<int, vector<int>, greater<>> pq;
    for (auto x : mp)
    {
        pq.push(x.first);
    }

    while (!pq.empty())
    {
        int first = pq.top();
        for (int i = first; i < first + gs; i++)
        {
            // if map does not have i return false
            if (mp.find(i) == mp.end())
            {
                return false;
            }
            // otherwise reduce from map
            mp[i]--;
            // if after reducing i map[i] becomes zero
            if (mp[i] == 0)
            {
                // and if its not in heap return false
                if (i != pq.top())
                {
                    return false;
                }
                // otherwise pop from heap
                pq.pop();
            }
        }
    }
    return true;
}
