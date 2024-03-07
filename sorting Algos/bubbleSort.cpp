#include <bits/stdc++.h>
using namespace std;
// compares two adjacent indexes and swaps them if arr[i]> arr[i+1]
// in 1 round we get last index as sorted and have max no.
// next round will run to n-2 (second last) then for n-3 ,n-4 and so on till it reaches index 1
// Time complexity - worst and average -O(N^2) but best -O(n) {when arr is already sorted}
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        int didSwap = 0;

        for (int j = 0; j <= i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
                didSwap = 1;
            }
        }
        if (didSwap == 0)
            break;
        cout << "-";
    }
}
int main()
{
    int n = 7;
    int arr[n] = {13, 46, 24, 52, 20, 9, 60};
    bubbleSort(arr, n);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
