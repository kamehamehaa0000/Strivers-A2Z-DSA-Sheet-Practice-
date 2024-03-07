
#include <bits/stdc++.h>
using namespace std;
// has duplicate elements and only have to return true and false not the index
/*
bool searchInARotatedSortedArrayII(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the array.
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
            return true;
    }
    return false;
}
*/
bool searchInARotatedSortedArrayII(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            return true;
                }
        if (nums[low] == nums[mid] && nums[low] == nums[high])
        {
            low += 1;
            high -= 1;
            continue;
        }
        // finding the sorted half
        if (nums[low] <= nums[mid]) // left half is sorted if
        {
            // check is target lies in this half or not

            if (nums[low] <= target && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else //(arr[low] > arr[mid])  right half is sorted if
        {
            if (nums[mid] < target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return 0;
}
int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool ans = searchInARotatedSortedArrayII(arr, k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}
