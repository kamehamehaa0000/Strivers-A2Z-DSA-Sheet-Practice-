#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node *prev;
    Node(string data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
    Node(string data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

class BrowserHistory
{
public:
    Node *current;
    BrowserHistory(string homepage)
    {
        current = new Node(homepage);
    }

    void visit(string url)
    {
        Node *newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    string back(int steps)
    {

        while (steps)
        {
            if (current->prev != nullptr)
            {
                current = current->prev;
                steps--;
            }
            else
            {
                break;
            }
        }
        return current->data;
    }

    string forward(int steps)
    {
        while (steps)
        {
            if (current->next != nullptr)
            {
                current = current->next;
                steps--;
            }
            else
            {
                break;
            }
        }
        return current->data;
    }
};