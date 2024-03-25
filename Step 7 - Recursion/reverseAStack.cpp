#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &stack, int x)
{
    if (stack.empty())
    {
        stack.push(x);
        return;
    }
    int top = stack.top();
    stack.pop();

    // recursive call
    insertAtBottom(stack, x);

    stack.push(top);
}
void reverseStack(stack<int> &stack)
{
    // basecase
    if (stack.empty())
    {
        return;
    }
    int x = stack.top();
    stack.pop();
    // recursive call
    reverseStack(stack);

    insertAtBottom(stack, x);
}