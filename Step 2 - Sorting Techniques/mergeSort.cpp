
#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    // putting left array values
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k];
        k++;
    }

    // putting right array values
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while (leftIndex < len1 && rightIndex < len2)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex++] = left[leftIndex++];
        }
        else
        {
            arr[mainArrayIndex++] = right[rightIndex++];
        }
    };

    // copy logic of left array

    while (leftIndex < len1)
    {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    // copy logic for right array
    while (rightIndex < len2)
    {
        arr[mainArrayIndex++] = right[rightIndex++];
    }
    delete[] left;
    delete[] right;
}
int mergeSort(int *arr, int s, int e)
{
    if (s >= e)
        return 0; // base Condition

    int mid = (s + e) / 2;
    mergeSort(arr, s, mid); // left

    mergeSort(arr, mid + 1, e); // right
    // int mid = start+end/2;
    // if(arr[mid]>arr[mid+1]){}
    // if(arr[mid]<arr[mid+1]){}
    merge(arr, s, e);
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