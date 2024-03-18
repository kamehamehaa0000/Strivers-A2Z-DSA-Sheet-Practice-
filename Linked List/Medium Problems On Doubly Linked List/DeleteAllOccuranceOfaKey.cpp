#include <bits/stdc++.h>
using namespace std;

// Definition of doubly linked list:
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node *deleteAllOccurrences(Node *head, int key)
{
    Node *temp = head;
    Node *prevNode = nullptr;
    Node *nextNode = nullptr;
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            if (temp == head) // if key is at head
            {
                head = head->next; // move the head to next node
            }
            nextNode = temp->next;
            prevNode = temp->prev;
            if (nextNode)
            {
                nextNode->prev = prevNode;
            }
            if (prevNode)
            {
                prevNode->next = nextNode;
            }
            free(temp);
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
