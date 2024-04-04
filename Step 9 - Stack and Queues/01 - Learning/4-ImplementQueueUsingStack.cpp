#include <bits/stdc++.h>
using namespace std;

// leetcode
// optimised 1
class MyQueue
{
    stack<int> input;
    stack<int> output;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        if (!output.empty())
        {
            int x = output.top();
            output.pop();
            return x;
        }
        else
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            int x = output.top();
            output.pop();
            return x;
        }
    }

    int peek()
    {
        if (!output.empty())
        {
            return output.top();
        }
        else
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }

    bool empty()
    {
        return input.empty() && output.empty();
    }
};

// recursive optimised solution
class MyQueue
{
    stack<int> s;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        s.push(x);
    }

    int pop()
    {
        if (s.empty())
        {
            return -1;
        }
        // Pop the current top element.
        int x = s.top();
        s.pop();

        // Base case of the recursion.
        if (s.empty())
        {
            return x;
        }
        //  Recursively pop the next element.
        int nxt = pop();
        // Push this element again to the stack.
        s.push(x);
        return nxt;
    }

    int peek()
    {
        if (s.empty())
        {
            return -1;
        }

        int x = s.top();
        s.pop();

        if (s.empty())
        {
            s.push(x);
            return x;
        }

        int nxt = peek();
        s.push(x);
        return nxt;
    }

    bool empty()
    {
        return (s.empty());
    }
};

// using 2 stack - costly push operation
class MyQueue
{
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        if (empty())
        {
            return -1;
        }
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int peek()
    {
        if (empty())
        {
            return -1;
        }
        return s1.top();
    }

    bool empty()
    {
        if (s1.empty())
            return true;
        else
        {
            return false;
        }
    }
};