#include <bits/stdc++.h>
using namespace std;

/*Striver solution */
class Queue1
{
    int *arr;
    int start, rear, currSize, maxSize;

public:
    Queue1()
    {
        arr = new int[16];
        start = -1;
        rear = -1;
        currSize = 0;
    }

    Queue1(int maxSize)
    {
        (*this).maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        rear = -1;
        currSize = 0;
    }

    void push(int newElement)
    {
        if (currSize == maxSize) // if Queue is full
        {
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }
        if (rear == -1) // if Queue is empty
        {
            start = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % maxSize; // % is useful when queue has space to store element but rear > maxSize
        }
        arr[rear] = newElement;
        cout << "The element pushed is " << newElement << endl;
        currSize++;
    }

    int pop()
    {
        if (start == -1) // if queue is empty
        {
            cout << "Queue Empty\nExiting..." << endl;
        }
        int popped = arr[start];
        if (currSize == 1) // if queue only has 1 element
        {
            start = -1;
            rear = -1;
        }
        else
        {
            start = (start + 1) % maxSize;
        }
        currSize--;
        return popped;
    }

    int top()
    {
        if (start == -1) // if Queue is empty
        {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }

    int size()
    {
        return currSize;
    }
};

/*Coding ninja Problem solution
class Queue
{
    int front, rear;
    vector<int> arr;

public:
    Queue()
    {
        front = 0;
        rear = 0;
        arr.resize(100001);
    }

    // Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e)
    {
        if (rear < arr.size())
        {
            arr[rear] = e;
            rear++;
        }
    }

    // Dequeue (retrieve) the element from the front of the queue.
    int dequeue()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            int x = arr[front];
            front++;
            return x;
        }
    }
    // // peek - returns the front element of the queue [not part of the coding ninja question]
    // int peek()
    // {
    //     if (front == -1)
    //     {
    //         cout << "Queue is Empty" << endl;
    //         exit(1);
    //     }
    //     return arr[front];
    // }
};*/
