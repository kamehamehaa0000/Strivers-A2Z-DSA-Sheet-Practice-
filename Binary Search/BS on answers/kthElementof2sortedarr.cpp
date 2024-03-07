#include <bits/stdc++.h>
using namespace std;
/*bruteForce
int kthelement(int array1[], int array2[], int m, int n, int k)
{
    int i = 0, j = 0, count = 0, ans = 0;

    while (i < m && j < n)
    {
        if (count == k)
            break;
        else if (array1[i] < array2[j])
        {
            ans = array1[i];
            i++;
        }
        else
        {
            ans = array2[j];
            j++;
        }
        count++;
    }
    if (count != k)
    {
        if (i != m - 1) // if arr1 is not exhausted
            ans = array1[k - count];
        else // if arr1 is exhausted we look in arr2
            ans = array2[k - count];
    }
    return ans;
}*/
int kthelement(int a[], int b[], int m, int n, int k)
{
    if (m < n)
    {
        kthelement(b, a, n, m, k);
    }
    // int leftLen = k;
    int low = max(0, k - m), high = min(k, n);
    // int low = 0;
    // int high = m;
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = k - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 >= 0)
        {
            l1 = a[mid1 - 1];
        }
        if (mid2 >= 0)
        {
            l2 = b[mid2 - 1];
        }
        if (mid1 < m)
        {
            r1 = a[mid1];
        }
        if (mid2 < n)
        {
            r2 = b[mid2];
        }
        // returing the kth element if symmetry is valid
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        // eliminating halves;

        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return 1;
}

int main()
{
    int array1[] = {2, 3, 6, 7, 9};
    int array2[] = {1, 4, 8, 10};
    int m = sizeof(array1) / sizeof(array1[0]);
    int n = sizeof(array2) / sizeof(array2[0]);
    int k = 5;
    cout << "The element at the kth position in the final sorted array is "
         << kthelement(array1, array2, m, n, k);
    return 0;
}