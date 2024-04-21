#include <bits/stdc++.h>
using namespace std;

// solution 1
int jump(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    int l = 0;
    int r = 0;
    while (r < n - 1)
    {
        int farthest = 0;
        for (int i = l; i <= r; i++)
        {
            farthest = max(farthest, nums[i] + i);
        }
        l = r + 1;
        r = farthest;
        cnt++;
    }
    return cnt;
}

// solution 2

int jump(vector<int> &nums)
{
    int cnt = 0;
    int end = 0;
    int farthest = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        farthest = max(farthest, i + nums[i]);
        if (farthest >= nums.size() - 1)
        {
            cnt++;
            break;
        }
        if (i == end)
        {                   // Visited all the items on the current level
            cnt++;          // Increment the level
            end = farthest; // Make the queue size for the next level
        }
    }
    return cnt;
}