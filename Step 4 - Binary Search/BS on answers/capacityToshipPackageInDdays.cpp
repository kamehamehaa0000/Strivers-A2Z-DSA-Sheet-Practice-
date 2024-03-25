#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE
int findDays(vector<int> &weights, int cap)
{
    int days = 1; // First day.
    int load = 0;
    int n = weights.size(); // size of array.
    for (int i = 0; i < n; i++)
    {
        if (load + weights[i] > cap)
        {
            days += 1;         // move to next day
            load = weights[i]; // load the weight.
        }
        else
        {
            // load the weight on the same day.
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    // Find the maximum and the summation:
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);

    for (int i = maxi; i <= sum; i++)
    {
        if (findDays(weights, i) <= d)
        {
            return i;
        }
    }
    // dummy return statement:
    return -1;
}*/
int findDays(vector<int> &weights, int cap)
{
    int days = 1;
    int load = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (load + weights[i] > cap)
        {
            days += 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return days;
}
int leastWeightCapacity(vector<int> &weights, int d)
{
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);

    int low = maxi;
    int high = sum;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (findDays(weights, mid) <= d)
        {
            high = mid - 1;
        }
        else //(findDays(weights, mid) > d)
        {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}
