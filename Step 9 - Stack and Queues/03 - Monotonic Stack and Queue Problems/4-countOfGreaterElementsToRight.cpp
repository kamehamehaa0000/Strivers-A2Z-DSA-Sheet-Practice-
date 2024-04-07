#include <bits/stdc++.h>
using namespace std;

// coding ninja problem solution but it does not require any stack

vector<int> countGreater(vector<int> &arr, vector<int> &query)
{
    int n = arr.size();
    int q = query.size();
    vector<int> ans(q, 0);

    for (int i = 0; i < q; i++) // for each query
    {
        int queryIndex = query[i];
        // Check for all the greater elements to the right.
        for (int j = queryIndex + 1; j < n; j++)
        {
            if (arr[j] > arr[queryIndex])
            {
                ans[i]++;
            }
        }
    }
    return ans;
}