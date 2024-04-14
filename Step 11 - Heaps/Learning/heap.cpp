#include <bits/stdc++.h>
using namespace std;

// heap is a complete binary tree with heap order property
// max heap --- parent > child
// min heap --- parent < child

// left child of ith index --- 2*i index
// right child of ith index --- 2*i+1 index

class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            // greater in case of min heap
            if (arr[parent] < val)
            {
                // swap parent and index
                int temp = arr[parent];
                arr[parent] = arr[index];
                arr[index] = temp;
                // make parent the new index
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    // deletion - (of root always)
    void deletion()
    {
        if (size == 0)
        {
            cout << "Nothing to return ";
            return;
        }
        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftChild = i * 2;
            int rightChild = i * 2 + 1;
            if (leftChild < size && arr[i] < arr[leftChild])
            {
                swap(arr[i], arr[leftChild]);
                i = leftChild;
            }
            else if (rightChild < size && arr[i] < arr[rightChild])
            {
                swap(arr[i], arr[rightChild]);
                i = rightChild;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.deletion();
    h.print();
}