#include <bits/stdc++.h>
using namespace std;
bool isSorted(int arr[], int n)
{
    bool sorted = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            // leave it blank
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n = 5;
    int arr[n] = {1, 2, 4, 3, 4, 5};
    cout << isSorted(arr, n);
    return 0;
}