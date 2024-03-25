
#include <bits/stdc++.h>
using namespace std;
/*Brute force
int findMin(vector<int> &arr)
{
    int n = arr.size(); // size of the array.
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        // Always keep the ansmum.
        ans = min(ans, arr[i]);
    }
    return ans;
}
*/
/*optimal solution 1 using binary search
int findMin(vector<int> arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[mid]) // if left part is sorted:

        {
            ans = min(arr[low], ans);
            low = mid + 1; // Eliminate left half:
        }
        else // if right part is sorted:
        {
            ans = min(arr[mid], ans);
            high = mid - 1; // Eliminate right half:
        }
    }
    return ans;
}*/

/*optimal solution 2 further optimisation*/
int findMin(vector<int> arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // search space is already sorted
        // then arr[low] will always be
        // the minimum in that search space:
        if (arr[low] <= arr[high])
        {
            ans = min(arr[low], ans);
            break;
        }
        if (arr[low] <= arr[mid]) // if left part is sorted:

        {
            ans = min(arr[low], ans);
            low = mid + 1; // Eliminate left half:
        }
        else // if right part is sorted:
        {
            ans = min(arr[mid], ans);
            high = mid - 1; // Eliminate right half:
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The ansmum element is: " << ans << "\n";
    return 0;
}
