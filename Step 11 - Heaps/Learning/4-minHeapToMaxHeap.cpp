#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int index)
{
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    // If left child is greater than replace it with node
    if (leftChild < n && arr[largest] < arr[leftChild])
    {
        largest = leftChild;
    }
    // If right child is greater than replace it with node
    if (rightChild < n && arr[largest] < arr[rightChild])
    {
        largest = rightChild;
    }

    // If any child has more value call heapify on corresponding sub-tree.
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, n, largest);
    }
}
vector<int> MinToMaxHeap(int n, vector<int> &arr)
{
    // Calling heapify process in bottom-up manner.
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    return arr;
}