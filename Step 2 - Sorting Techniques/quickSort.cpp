#include <bits/stdc++.h>
using namespace std;

// Time Complexity - o(nlogn) space - O(1) without recursive stack in account
//  1. take a pivot element (first or last element usually but can be anything)
//  2. pick and place it in its correct position in array
//  2. smaller on left larger on right
//  4. repeat these steps

int partition(vector<int> &arr, int low, int high)
{
    // this function will give the index of pivot element after placing it in its correct position

    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) // runs till i not crosses j
    {
        // looking for i(value of element at i) greater than pivot
        while (arr[i] <= pivot && i <= high - 1) // if value at i is smaller than pivot move to right by i++
        {
            i++;
        }
        // looking for j(value of element at j) smaller than pivot
        while (arr[j] > pivot && j >= low + 1) // if value at j is bigger than pivot move to left by j--
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high); // this function will give the correct index of pivot element after placing it in its correct position
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}
int main()
{
    int n = 8;
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    quickSort(arr, 0, n - 1);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}