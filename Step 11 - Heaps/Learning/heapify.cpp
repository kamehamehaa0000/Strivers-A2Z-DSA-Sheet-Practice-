#include <bits/stdc++.h>
using namespace std;
// Max Heap
void heapify(vector<int> &arr, int n, int index)
{
    int largest = index;
    int leftChild = index * 2;
    int rightChild = index * 2 + 1;
    if (leftChild < n && arr[largest] < arr[leftChild])
    {
        largest = leftChild;
    }
    if (rightChild < n && arr[largest] < arr[rightChild])
    {
        largest = rightChild;
    }
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(vector<int> &arr, int n)
{ // only processing heap nodes (not leaf nodes) and no. of leaf node for n is n/2+1
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}

// Min Heap
void heapify(vector<int> &arr, int n, int index)
{
    int smallest = index;
    int leftChild = index * 2 + 1;
    int rightChild = index * 2 + 2;
    if (leftChild < n && arr[smallest] > arr[leftChild])
    {
        smallest = leftChild;
    }
    if (rightChild < n && arr[smallest] > arr[rightChild])
    {
        smallest = rightChild;
    }
    if (smallest != index)
    {
        swap(arr[smallest], arr[index]);
        heapify(arr, n, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    return arr;
}

int main()
{
    vector<int> arr = {-1, 54, 53, 55, 52, 50};
    buildMaxHeap(arr, 5);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    buildMinHeap(arr);

    for (auto i : arr)
    {
        cout << i << " ";
    }
}