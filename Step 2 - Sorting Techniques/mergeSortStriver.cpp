#include <bits/stdc++.h>
using namespace std;
// divide and merge
// time complexity- O(NlogN)

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    // comparing the element in left and right array and pushing to temp array
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // pushing the remaining elements from left or right array after one's exhaustion to the temp array

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // copying temp to original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void mergeSort(vector<int> &arr, int low, int high)
{

    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;
    // divide
    mergeSort(arr, low, mid);      // left
    mergeSort(arr, mid + 1, high); // right

    // merge
    merge(arr, low, mid, high);
}
int main()
{
    int n = 7;
    vector<int> arr = {13, 46, 24, 52, 20, 9, 60};
    mergeSort(arr, 0, n - 1);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}