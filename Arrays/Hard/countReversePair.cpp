#include <bits/stdc++.h>
using namespace std;
/*BruteForce
int reversePairs(vector<int> &a, int n)
{

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > 2 * a[j])
                cnt++;
        }
    }
    return cnt;
}
*/
// OPTIMAL-

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // storing elements in the temporary array in a sorted manner//
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if elements on the left half are still left //
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &a, int low, int high)
{
    int cnt = 0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        cnt += mergeSort(a, low, mid);        // left half
        cnt += mergeSort(a, mid + 1, high);   // right half
        cnt += countPairs(a, low, mid, high); // Modification
        merge(a, low, mid, high);             // merging sorted halves
    }
    return cnt;
}
int reversePair(vector<int> &a, int n)
{
    return mergeSort(a, 0, n - 1);
}
int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = reversePair(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}
