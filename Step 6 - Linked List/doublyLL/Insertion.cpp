#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }

public:
    Node(int data1, Node *back1, Node *next1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
};
Node *convertArrToDLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        newNode->back = prev;
        // newNode->next = nullptr; // its already null cause of contructor used
        prev->next = newNode;
        prev = newNode; // or prev= prev->next;
    }
    return head;
}
void printDLL(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *insertBeforeHead(Node *head, int data)
{
    Node *newNode = new Node(data); // nxt->nullptr and back->nullptr
    if (head == nullptr)
    {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head->back = newNode;
    head = newNode;
    return head;
}

Node *insertBeforeTail(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        return head;
    }
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    Node *prev = tail->back;
    prev->next = newNode;
    newNode->back = prev;
    newNode->next = tail;
    tail->back = newNode;
    return head;
}

Node *insertBeforeKthNode(Node *head, int data, int k)
{
    if (k == 1)
    {
        return insertBeforeHead(head, data);
    }
    Node *temp = head;
    int cnt = 0;
    Node *newNode = new Node(data);
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
        {
            Node *prev = temp->back;
            newNode->back = prev;
            newNode->next = temp;
            prev->next = newNode;
            temp->back = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

void insertBeforeGivenNode(Node *given, int data)
{
    Node *prev = given->back;
    Node *newNode = new Node(data);
    newNode->back = prev;
    newNode->next = given;
    prev->next = newNode;
    given->back = newNode;
    return;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArrToDLL(arr);
    printDLL(head);
    head = insertBeforeHead(head, 0); // 0 1 2 3 4 5
    printDLL(head);
    head = insertBeforeTail(head, 10); // 0 1 2 3 4 10 5
    printDLL(head);
    head = insertBeforeKthNode(head, 30, 3); // 0 1 30 2 3 4 10 5
    printDLL(head);
    insertBeforeGivenNode(head->next->next, 90); // 0 1 90 30 2 3 4 10 5
    printDLL(head);
}