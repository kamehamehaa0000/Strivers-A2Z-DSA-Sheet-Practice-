#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &ans, int i, vector<int> arr, vector<int> temp, int target)
{
    if (i == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(temp);
        }
        return;
    }
    // include
    if (arr[i] <= target)
    {
        temp.push_back(arr[i]);
        helper(ans, i, arr, temp, target - arr[i]);
        temp.pop_back();
    }
    // exclude
    helper(ans, i + 1, arr, temp, target);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;

    helper(ans, 0, candidates, temp, target);
    return ans;
}

/*
class Solution {
public:

void helper(vector<vector<int>> &ans, int i, vector<int> arr, vector<int> temp, int target)
{
    if (i == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(temp);
        }
        return;
    } // exclude
    helper(ans, i + 1, arr, temp, target);
    // include
    if (arr[i] <= target)
    {
        temp.push_back(arr[i]);
        helper(ans, i, arr, temp, target - arr[i]);

    }

}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;

    helper(ans, 0, candidates, temp, target);
    return ans;
}
};*/