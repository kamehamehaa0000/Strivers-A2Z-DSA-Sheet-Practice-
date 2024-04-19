#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char> &tasks, int n)
{
    int time = 0;
    vector<int> mp(26, 0);  // hashmap for freq of tasks
    priority_queue<int> pq; // max heap

    // store freq of each task into hashmap
    for (char task : tasks)
    {
        mp[task - 'A']++;
    }
    // push freq into max heap
    for (int i = 0; i < 26; i++)
    {
        if (mp[i] > 0)
        {
            pq.push(mp[i]);
        }
    }
    // calculate time
    while (!pq.empty())
    {
        vector<int> temp; // to store current tasks freq in current iteration
        for (int i = 0; i < n + 1; i++)
        {
            // execute a task and decrease it frequency
            if (!pq.empty())
            {
                int freq = pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
            }
        }

        for (int f : temp)
        {
            // if frequency is greater than zero push back to max heap
            if (f > 0)
            {
                pq.push(f);
            }
        }

        if (pq.empty())
        {
            time += temp.size();
        }
        else
        {
            time += n + 1;
        }
    }
    return time;
}