#include <bits/stdc++.h>
using namespace std;
int SecondLargestNumber(int arr[], int n)
{
    int largest = arr[0];
    int secondLargest = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}
int main()
{
    int n = 5;
    int arr[n] = {6, 5, 1, 4, 2};
    cout << SecondLargestNumber(arr, n);
    return 0;
}