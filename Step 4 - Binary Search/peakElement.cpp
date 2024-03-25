#include <bits/stdc++.h>
using namespace std;
/*bruteForce
int findPeakElement(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        // Checking for the peak
        if ((i == 0 || (arr[i - 1] < arr[i])) && (i == n - 1 || (arr[i] > arr[i + 1])))
        {
            return i;
        }
    }
    return -1;
}
*/

/*optimal using binary search*/
int findPeakElement(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;
    // edge cases
    if (arr.size() == 1)
    {
        return 0;
    }
    if (arr[0] > arr[1])
    {
        return 0;
    }
    if (arr[arr.size() - 1] > arr[arr.size() - 2])
    {
        return arr.size() - 1;
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        // if peak is right of mid
        if (arr[mid - 1] < arr[mid]) // linearly increasing graph so peak will be on right
        {
            low = mid + 1;
        }
        else // (arr[mid + 1] < arr[mid]) // linearly decreasing graph so peak will be on left
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}
