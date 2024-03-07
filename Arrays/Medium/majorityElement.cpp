#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> arr)
{

    /*brute Force
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
                count++;
        }
        if (count > n / 2)
        {
            return arr[i];
        }
    }
    */

    /*
    // Better hashing

    int n = arr.size();
    int count = 0;
    map<int, int> mpp; // el(key) count(value)
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]] = mpp[arr[i]] + 1;
    }
    for (auto it : mpp)
    {
        if (it.second > n / 2)
        {
            return it.first;
        }
    }
    return -1;

    */
    /* //Optimal Solution
    //moore's Voting Algo
    Initialize 2 variables:
    Count –  for tracking the count of element
    Element – for which element we are counting
    Traverse through the given array.
    If Count is 0 then store the current element of the array as Element.
    If the current element and Element are the same increase the Count by 1.
    If they are different decrease the Count by 1.
    The integer present in Element should be the result we are expecting
     */
    int n = arr.size();
    int count = 0;
    int el;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            el = arr[i];
        }
        else if (arr[i] == el)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return el;
}
int main()
{

    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int n = arr.size();
    int target = 14;
    cout << majorityElement(arr);

    return 0;
}