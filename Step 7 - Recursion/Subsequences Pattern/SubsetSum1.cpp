#include <bits/stdc++.h>
using namespace std;

void subsetSumsHelper(int ind, vector<int> &arr, int n, vector<int> &ans, int sum)
{
    if (ind == n)
    {
        ans.push_back(sum);
        return;
    }
    // include
    subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
    // exclude
    subsetSumsHelper(ind + 1, arr, n, ans, sum);
}

vector<int> subsetSum(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}
