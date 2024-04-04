#include <bits/stdc++.h>
using namespace std;
class Stack
{
    int *arr;
    int topp;
    int size;

public:
    Stack(int capacity)
    {
        arr = new int[capacity];
        topp = -1;
        size = capacity;
    }

    void push(int num)
    {
        if (topp != size - 1)
        {
            topp++;
            arr[topp] = num;
        }
    }

    int pop()
    {
        if (topp == -1)
        {
            return -1;
        }
        int x = arr[topp];
        topp--;
        return x;
    }

    int top()
    {
        if (topp != -1)
        {
            return arr[topp];
        }
        return -1;
    }

    int isEmpty()
    {
        if (topp == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isFull()
    {
        if (topp == size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};