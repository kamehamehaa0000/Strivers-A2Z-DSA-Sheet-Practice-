#include <bits/stdc++.h>
using namespace std;
void sort(vector<int> &arr)
{
    /*BruteForce is merge sort or quick sort NlogN*/
    /*Better O(2N);
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
            count1++;
        else if (arr[i] == 2)
            count2++;
        else
        {
            count0++;
        }
    }

    for (int i = 0; i < count0; i++)
    {
        arr[i] = 0;
    }
    for (int i = count0; i < (count0 + count1); i++)
    {
        arr[i] = 1;
    }
    for (int i = (count0 + count1); i < arr.size(); i++)
    {
        arr[i] = 2;
    }*/

    /*Optimal DNF algo (dutch national flag )

    uses 3 pointer
    low mid high
    This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.  The rules are the following:

    arr[0….low-1] contains 0. [Extreme left part]
    arr[low….mid-1] contains 1.
    arr[mid...high] contains random no.(not sorted)
    arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array

*/ int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid < high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        if (arr[mid] == 1)
        {
            mid++;
        }
        if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
            mid++;
        }
    }
}
int main()
{

    vector<int> arr = {2, 0, 2, 1, 1, 0};
    int n = arr.size();
    int target = 14;
    sort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}