#include <bits/stdc++.h>
using namespace std;

// check for minimum and swap it with the start pointer
// and after every round increment start pointer
// Time complexity(n-2 * n-2) or O(n^2) worst best average all

void selectionSort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min = i;
        int temp;
        for (int j = i; j <= n - 1; j++)
        {

            if (arr[j] < arr[min])
            {
                min = j;
            }
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
int main()
{

    int n = 6;
    int arr[n] = {13, 46, 24, 52, 20, 9};
    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}