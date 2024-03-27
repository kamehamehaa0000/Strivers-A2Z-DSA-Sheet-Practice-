#include <bits/stdc++.h>
using namespace std;

/*Brute Force -- gives TLE */
void helper(vector<vector<int>> &ans, int i, vector<int> arr, vector<int> temp, int target)
{
    if (i == arr.size())
    {
        if (target == 0)
        {
            bool isPresent = find(ans.begin(), ans.end(), temp) != ans.end();
            if (!isPresent)
            {
                ans.push_back(temp);
            }
        }
        return;
    }
    // include
    temp.push_back(arr[i]);
    helper(ans, i + 1, arr, temp, target - arr[i]);
    temp.pop_back();
    // exclude
    helper(ans, i + 1, arr, temp, target);
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    helper(ans, 0, candidates, temp, target);
    return ans;
}

/*Optimal*/

void helper(vector<vector<int>> &ans, int i, vector<int> arr, vector<int> temp, int target)
{

    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }

    for (int k = i; k < arr.size(); k++)
    {
        if (k > i && arr[k] == arr[k - 1])
        {
            continue;
        }
        if (arr[k] > target)
        {
            break;
        }
        temp.push_back(arr[k]);
        helper(ans, k + 1, arr, temp, target - arr[k]);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    vector<int> temp;
    helper(ans, 0, candidates, temp, target);
    return ans;
}