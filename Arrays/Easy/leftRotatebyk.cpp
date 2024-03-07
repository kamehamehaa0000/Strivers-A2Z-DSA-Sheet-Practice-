#include <bits/stdc++.h>
using namespace std;
void leftRotatebyOnePlace(vector<int> &arr, int k)
{
    int n = arr.size();
    k = k % n;

    vector<int> temp{k}; // elements that will be rotated
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = k; i < n; i++) // shifting the array
    {
        arr[i - k] = arr[i];
    }
    for (int i = n - k; i < n; i++) // putting back temp in arr
    {
        arr[i] = temp[i - (n - k)];
    }
    /*
    optimal solution
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
    reverse(arr,arr+n);
    */
}
int main()
{

    vector<int> arr = {6, 5, 1, 4, 2};
    leftRotatebyOnePlace(arr, 3);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << " " << arr[i] << " ";
    }

    return 0;
}