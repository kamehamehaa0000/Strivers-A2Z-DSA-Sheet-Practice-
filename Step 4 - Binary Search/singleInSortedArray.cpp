#include <bits/stdc++.h>
using namespace std;
/*Brute using XOR
int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size(); // size of the array.
    int ans = 0;
    // XOR all the elements:
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}*/
/*
int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    if(n==1) {return arr[0];}
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (arr[i + 1] != arr[i])
            {
                return arr[i];
            }
        }
        else if (i == n - 1)
        {
            if (arr[i - 1] != arr[i])
            {
                return arr[i];
            }
        }
        else
        {
            if (arr[i - 1] != arr[i] && arr[i + 1] != arr[i])
            {
                return arr[i];
            }
        }
    }
}*/
/*optimal binary search -- even index odd index*/
int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
    {
        return arr[0];
    }
    if (arr[0] != arr[1])
    {
        return arr[0];
    }
    if (arr[n - 1] != arr[n - 2])
    {
        return arr[n - 1];
    }
    // edge case for first and last is handled in above statements
    int low = 1;
    int high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }
        // currently at left half but element is on right half-- either mid is on even index (and equal to prev index) and mid is on odd index (and equal to next index) means we are on left but ans is on right side
        if ((mid % 2 == 1 && arr[mid - 1] == arr[mid]) || (mid % 2 == 0 && arr[mid + 1] == arr[mid]))
        {
            // eliminate left
            low = mid + 1;
        }
        // on right half
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}
