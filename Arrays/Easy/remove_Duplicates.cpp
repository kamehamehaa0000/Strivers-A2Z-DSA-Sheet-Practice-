#include <bits/stdc++.h>
using namespace std;
// bruteForce
int removeDuplicates_bruteForce(vector<int> &arr, int &n)
{
    set<int> set;
    // inserted unique element in a set
    for (int i = 0; i < n; i++)
    {
        set.insert(arr[i]);
    }
    // finding the no. of unique elements
    int index = 0;
    for (auto it : set)
    {
        arr[index] = it;
        index++;
    }
    n = index; // making the size of array = no. of unique elements //optional
    return index;
}

// Optimal
int removeDuplicates(int arr[], int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}
int main()
{
    int arr[] = {1, 1, 2, 2, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = removeDuplicates(arr, n);
    cout << "The array after removing duplicate elements is " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}