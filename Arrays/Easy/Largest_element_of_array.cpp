#include <bits/stdc++.h>
using namespace std;
void largestNumber(int arr[], int n)
{
    int max = arr[0]; // assuming first element is largest
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << max << endl;
}
int main()
{
    int n = 5;
    int arr[n] = {3, 2, 1, 5, 2};
    largestNumber(arr, n);
    return 0;
}