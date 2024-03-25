#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &stack, int key)
{
    // base case
    if (stack.empty() || key > stack.top())
    {
        stack.push(key);
        return;
    }

    int top = stack.top();
    stack.pop();

    // recursive call
    sortedInsert(stack, key);

    stack.push(top);
}

void sortStackHelper(stack<int> &s)
{ // base case
    if (s.empty())
    {
        return;
    }

    int top = s.top();
    s.pop();
    // recursive call
    sortStackHelper(s);

    sortedInsert(s, top);
}

stack<int> sortStack(stack<int> &s)
{
    sortStackHelper(s);
    return s;
}