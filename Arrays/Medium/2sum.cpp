#include <bits/stdc++.h>
using namespace std;
string twoSum(int n, vector<int> arr, int target)
{
    /*
    BruteForce
    for (int i = 0; i < n; i++)
     {
         for (int j = i; j < n; j++)
         {
             if (arr[i] + arr[j] == target)
             {
                 // Convert integers to strings and concatenate
                 ostringstream oss;
                 oss << i << " and " << j;
                 return oss.str();
             }
         }
     }
     */

    // Better -  hashing
    map<int, int> mpp; // element (key) ,index(value)
    for (int i = 0; i < n; i++)
    {
        int rem = target - arr[i];
        if (mpp.find(rem) != mpp.end())
        {
            ostringstream oss;
            oss << mpp[rem] << " and " << i;
            return oss.str();
        }
        else
        {
            mpp[arr[i]] = i;
        }
    }

    // Optimal 2-pointer only on sorted array - same time complexity as better one without using map
    /*  only answer yes and no does not give indexes
        int i = 0;
        int j = n - 1;
        sort(arr.begin(), arr.end());
        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (sum == target)
            {
                ostringstream oss;
                oss << i << " and " << j;
                return oss.str();
            }
            else if (sum < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return "NO";*/
}
int main()
{

    vector<int> arr = {2, 6, 5, 8, 11};
    int n = arr.size();
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << "This is the answer : " << ans << endl;

    return 0;
}