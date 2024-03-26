#include <bits/stdc++.h>
using namespace std;

bool helper(int i, int k, int sum, vector<int> vec)
{

    if (sum > k)
    {
        return false;
    }

    if (i == vec.size())
    {

        if (sum == k)
        {

            return true;
        }

        return false;
    }

    sum += vec[i];

    if (helper(i + 1, k, sum, vec) == true)
        return true;

    sum -= vec[i];

    if (helper(i + 1, k, sum, vec) == true)
        return true;

    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    return helper(0, k, 0, a);
}
