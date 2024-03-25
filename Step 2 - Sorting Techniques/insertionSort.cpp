#include <bits/stdc++.h>
using namespace std;
// takes an element and insert it in correct position
// time complexity - worst(reversed arr) and avg- O(n^2) best- O(N)
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void insertionSort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {

        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr, j - 1, j);
            j--; // moving to left
        }
    }
}
int main()
{
    int n = 7;
    int arr[n] = {13, 46, 24, 52, 20, 9, 60};
    insertionSort(arr, n);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
