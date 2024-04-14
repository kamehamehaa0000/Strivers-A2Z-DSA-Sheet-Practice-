#include <bits/stdc++.h>
using namespace std;

bool isMinHeap(const vector<int> &arr)
{
    int n = arr.size();

    // Traverse through all internal nodes from last non-leaf node up to the root
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        // If an internal node is greater than any of its children, return false
        if (leftChild < n && arr[i] > arr[leftChild] ||
            (rightChild < n && arr[i] > arr[rightChild]))
        {
            return false;
        }
    }

    return true;
}
bool isMaxHeap(const vector<int> &arr)
{
    int n = arr.size();

    // Traverse through all internal nodes from last non-leaf node up to the root
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        // If an internal node is greater than any of its children, return false
        if (leftChild < n && arr[i] < arr[leftChild] ||
            (rightChild < n && arr[i] < arr[rightChild]))
        {
            return false;
        }
    }

    return true;
}