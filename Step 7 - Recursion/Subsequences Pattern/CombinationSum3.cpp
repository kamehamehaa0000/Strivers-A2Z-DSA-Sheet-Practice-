#include <bits/stdc++.h>
using namespace std;

void helper(int ind, vector<int> &temp, vector<vector<int>> &ans, int target, int k)
{
    if (k == 0 && target == 0)
    {

        bool isPresent = find(ans.begin(), ans.end(), temp) != ans.end();
        if (!isPresent)
        {
            ans.push_back(temp);
        }
        return;
    }
    if (ind > 9 || k <= 0)
    {
        return;
    }
    if (target < 0)
    {
        return;
    }
    // include
    temp.push_back(ind);
    helper(ind + 1, temp, ans, target - ind, k - 1);
    temp.pop_back();
    // exclude
    helper(ind + 1, temp, ans, target, k);
}
vector<vector<int>> combinationSum3(int k, int n)
{

    vector<vector<int>> ans;
    vector<int> temp;
    helper(1, temp, ans, n, k);
    return ans;
}

/* 2nd way to write same code*/
void helper(int ind, int sum, int n, int k, vector<int> &temp, vector<vector<int>> &ans)
{
    if (sum == n && k == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (sum > n)
    {
        return;
    }
    for (int i = ind; i <= 9; i++)
    {
        if (i > n)
        {
            break;
        }
        temp.push_back(i);
        helper(i + 1, sum + i, n, k - 1, temp, ans);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{

    vector<vector<int>> ans;
    vector<int> temp;
    helper(1, 0, n, k, temp, ans);
    return ans;
}