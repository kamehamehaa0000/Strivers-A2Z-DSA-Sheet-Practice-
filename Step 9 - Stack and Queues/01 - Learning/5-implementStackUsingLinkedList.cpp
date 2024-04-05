#include <bits/stdc++.h>
using namespace std;
// node class
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

// stack using LL
class Stack
{
    int size;
    Node *top;

public:
    Stack()
    {
        top = nullptr;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop()
    {
        if (top == nullptr)
        {
            return;
        }
        Node *prev = top;
        top = top->next;
        free(prev);
        size--;
    }

    int getTop()
    {
        if (top == nullptr)
        {
            return -1;
        }
        return top->data;
    }
};