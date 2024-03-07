#include <bits/stdc++.h>
using namespace std;

int maxProfits(vector<int> &arr)
{
    /*BruteForce

    int n = arr.size();
    int maxDiff = 0; // also known as Profit
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                maxDiff = max(maxDiff, arr[j] - arr[i]);
            }
        }
    }
    return maxDiff;

    */
    /*
    Optimal
    */
    int min = INT_MAX;
    int maxi = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        maxi = max(maxi, arr[i] - min);
    }
    return maxi;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    int maxPro = maxProfits(arr);
    cout << "Max profit is: " << maxPro << endl;
    return 0;
}