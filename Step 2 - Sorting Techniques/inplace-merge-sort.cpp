
#include <iostream>
using namespace std;

void merge(int *arr, int s, int mid, int e)
{
    int leftIndex = s;
    int rightIndex = mid + 1;
    while (leftIndex <= mid && rightIndex <= e) // looping till one of the array gets exhausted
    {
        if (arr[leftIndex] <= arr[rightIndex]) // if element in left is sorted then move the left pointer by one
        {
            leftIndex++;
        }
        else
        {
            int temp = arr[rightIndex];
            int i = rightIndex;
            while (i > leftIndex)
            {
                arr[i] = arr[i - 1];
                i--;
            }
            arr[leftIndex] = temp;
            leftIndex++;
            rightIndex++;
            mid++;
        }
    }
}
int mergeSort(int *arr, int s, int e)
{
    if (s >= e)
        return 0; // base Condition

    int mid = (s + e) / 2;
    mergeSort(arr, s, mid); // left

    mergeSort(arr, mid + 1, e); // right

    merge(arr, s, mid, e);
}

int main()
{
    int arr[] = {38, 27, 43, 56, 45};
    int n = 5;
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*leetcode
void merge(vector<int> &nums, int low, int mid, int high)
{
    if (low >= high)
    {
        return;
    }
    int l = low, r = mid + 1;
    while (l <= mid and r <= high)
    {
        if (nums[l] <= nums[r])
        {
            l++;
        }
        else
        {
            int val = nums[r];
            for (int k = r++; k > l; k--)
            {
                nums[k] = nums[k - 1];
            }
            nums[l++] = val;
            mid++;
        }
    }
}

void mergeSort(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return;
    int mid = (high - low) / 2 + low;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}
vector<int> sortArray(vector<int> &nums)
{
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
}
*/