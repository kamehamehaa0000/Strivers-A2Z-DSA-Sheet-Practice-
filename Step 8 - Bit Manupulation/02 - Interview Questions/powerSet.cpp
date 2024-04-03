#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    int noOfSubsets = 1 << nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < noOfSubsets; i++)
    {
        vector<int> temp;
        for (int j = 0; j < nums.size(); j++)
        {
            if ((i & (1 << j)))
            {
                temp.push_back(nums[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}