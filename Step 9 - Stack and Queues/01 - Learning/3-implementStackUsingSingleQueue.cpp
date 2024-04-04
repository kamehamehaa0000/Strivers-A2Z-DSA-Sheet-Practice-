#include <bits/stdc++.h>
using namespace std;

/*using 1 queue*/
class Stack
{
    queue<int> *q;

public:
    Stack()
    {
        q = new queue<int>();
    }

    int getSize()
    {
        return q->size();
    }

    bool isEmpty()
    {
        return getSize() == 0;
    }

    void push(int element)
    {
        int size = q->size();
        q->push(element);
        for (int i = 0; i < size; i++)
        {
            q->push(q->front());
            q->pop();
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            return -1;
        }
        int ans = q->front();
        q->pop();
        return ans;
    }

    int top()
    {
        return q->front();
    }
};

/*using two Queues
class Stack
{

public:
    queue<int> q1;
    queue<int> q2;

    Stack()
    {
    }

    int getSize()
    {
        return q1.size();
    }

    bool isEmpty()
    {
        return q1.empty();
    }

    void push(int element)
    {
        q2.push(element);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        if (q1.size() != 0)
        {
            int N = top();
            q1.pop();
            return N;
        }
        else
        {
            return -1;
        }
    }

    int top()
    {
        if (q1.size() != 0)
        {
            return q1.front();
        }
        else
        {
            return -1;
        }
    }
};
*/