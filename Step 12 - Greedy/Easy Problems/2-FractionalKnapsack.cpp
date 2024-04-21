#include <bits/stdc++.h>
using namespace std;

// coding ninjas solution
bool compare(pair<int, int> &a, pair<int, int> &b)
{
    double x = (double)a.second / a.first;
    double y = (double)b.second / b.first;
    return x > y;
}
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{

    sort(items.begin(), items.end(), compare);
    double ans = 0;
    int currentWeight = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentWeight + items[i].first <= w)
        {
            currentWeight += items[i].first;
            ans += items[i].second;
        }
        else
        {
            int remaining = w - currentWeight;
            currentWeight += remaining;
            ans += ((double)items[i].second / items[i].first) * remaining;
        }
    }
    return ans;
}

// geek for geek Solution
struct Item
{
    int value;
    int weight;
};
double fractionalKnapsack(int W, Item arr[], int n)
{
    // sort items on basis of value per weight
    sort(arr, arr + n, [](const auto &a, const auto &b)
         {
            double x = (double)(a.value) / (double)(a.weight);
            double y = (double)(b.value) / (double)(b.weight);
            return  x > y; });

    double ans = 0.0;
    int i = 0;
    while (W > 0 && i < n)
    {
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            ans += arr[i].value;
        }
        else
        {
            ans += ((double)(arr[i].value) / (double)(arr[i].weight)) * (double)(W);
            W = 0;
        }
        i++;
    }
    return ans;
}