#include <bits/stdc++.h>
using namespace std;

vector<int> MinimumCoins(int n)
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> ans;
    int i = coins.size() - 1;
    while (i >= 0)
    {
        if (coins[i] <= n)
        {
            n = n - coins[i];
            ans.push_back(coins[i]);
        }
        else
        {
            i--;
        }
    }
    return ans;
}