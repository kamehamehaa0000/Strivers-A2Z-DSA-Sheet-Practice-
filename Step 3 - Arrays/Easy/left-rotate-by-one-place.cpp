#include <bits/stdc++.h>
using namespace std;
void leftRotatebyOnePlace(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}
int main()
{
    int n = 5;
    int arr[n] = {6, 5, 1, 4, 2};
    leftRotatebyOnePlace(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i] << " ";
    }

    return 0;
}