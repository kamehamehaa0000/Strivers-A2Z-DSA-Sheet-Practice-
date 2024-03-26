#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> a, int i, vector<int> temp, int sum, int k, vector<vector<int>> &ans, set<vector<int>> &uniqueSubarrays)
{
    if (i == a.size())
    {
        sort(temp.begin(), temp.end());
        if (sum == k && uniqueSubarrays.find(temp) == uniqueSubarrays.end())
        {
            ans.push_back(temp);
            uniqueSubarrays.insert(temp);
        }
        return;
    }
    // include
    temp.push_back(a[i]);
    sum = sum + a[i];
    helper(a, i + 1, temp, sum, k, ans, uniqueSubarrays);
    sum = sum - a[i];
    temp.pop_back();

    // exclude
    helper(a, i + 1, temp, sum, k, ans, uniqueSubarrays);
}
vector<vector<int>> subarraysWithSumK(vector<int> a, long long k)
{
    vector<vector<int>> ans;
    vector<int> temp;
    set<vector<int>> uniqueSubarrays; // Set to store unique subarrays
    helper(a, 0, temp, 0, k, ans, uniqueSubarrays);
    return ans;
}

/*
   brute force non recursive solution
*/
vector<vector<int>> subarraysWithSumK(vector<int> a, long long k)
{

    int n = a.size();

    vector<vector<int>> ans;
    // Iterating over 'a'
    for (int i = 0; i < n; ++i)
    {
        long long currentSum = 0;

        vector<int> temp;
        for (int j = i; j < n; ++j)
        {
            temp.push_back(a[j]);
            currentSum += a[j];

            if (currentSum == k)
            {
                ans.push_back(temp);
            }
        }
    }

    return ans;
}

/*
  two pointer optimal solution
*/

vector<vector<int>> subarraysWithSumK(vector<int> a, long long k)
{

    int n = a.size();

    vector<vector<int>> ans;

    // start and end are the starting
    // and the ending indices of our current subarray
    int start = 0, end = -1;
    long long currentSum = 0;

    // Iterating over 'a'
    while (start < n)
    {

        // Increasing the right end
        // till our sum <= ‘k’ or we
        // are not out of bounds
        while ((end + 1 < n) && (currentSum + a[end + 1] <= k))
        {
            currentSum += a[end + 1];
            ++end;
        }

        // We have found a subarray with the
        //  required sum.
        if (currentSum == k)
        {
            vector<int> temp;

            for (int i = start; i <= end; ++i)
            {
                temp.push_back(a[i]);
            }
            ans.push_back(temp);
        }

        // Shifting the start index
        currentSum -= a[start];
        ++start;
    }

    return ans;
}

/*Another recursive approach but gives TLE*/
#include <bits/stdc++.h>

set<vector<int>> st;

void helper(int ind, vector<int> &a, long long k, vector<int> &temp, vector<vector<int>> &res)
{

    if (ind > a.size())
        return;

    if (k == 0 && st.find(temp) == st.end())
    {

        res.push_back(temp);

        st.insert({temp});
    }

    if (a[ind] <= k)
    {

        for (int i = ind; i <= a.size(); i++)
        {

            temp.push_back(a[i]);

            helper(i + 1, a, k - a[i], temp, res);

            temp.pop_back();
        }
    }

    return;
}

vector<vector<int>> subarraysWithSumK(vector<int> a, long long k)
{

    vector<vector<int>> res;

    vector<int> temp;

    helper(0, a, k, temp, res);

    return res;
}