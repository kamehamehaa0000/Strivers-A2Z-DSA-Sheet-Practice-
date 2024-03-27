#include <bits/stdc++.h>
using namespace std;
/*brute Force */
void helper(int ind, vector<int> temp, vector<int> &arr, int n, vector<vector<int>> &ans)
{
    if (ind == n)
    {
        bool isPresent = find(ans.begin(), ans.end(), temp) != ans.end();
        if (!isPresent)
        {
            ans.push_back(temp);
        }
        return;
    }
    // include
    temp.push_back(arr[ind]);
    helper(ind + 1, temp, arr, n, ans);
    temp.pop_back();
    // exclude
    helper(ind + 1, temp, arr, n, ans);
}

vector<vector<int>> subsetsWithDup(vector<int> &arr)

{
    int n = arr.size();
    vector<vector<int>> ans;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    helper(0, temp, arr, n, ans);
    return ans;
}

/*Optimal*/
void helper(int ind, vector<int> temp, vector<int> &arr, int n, vector<vector<int>> &ans)
{
    ans.push_back(temp);

    for (int i = ind; i < arr.size(); i++)
    {
        if (i != ind && arr[i] == arr[i - 1])
        {
            continue;
        }
        temp.push_back(arr[i]);
        helper(i + 1, temp, arr, n, ans);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    helper(0, temp, arr, n, ans);
    return ans;
}