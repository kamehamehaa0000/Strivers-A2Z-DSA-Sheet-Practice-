#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node *convertArrToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp; // or mover = mover->next;
    }
    return head;
}
void printLL(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *insertAtHead(Node *head, int data)
{
    Node *newNode = new Node(data, head);
    newNode->next = head;
    head = newNode;
    return head;
    /*or
    return new Node(data, head);
    */
}
Node *insertAtTail(Node *head, int data)
{
    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);
    return head;
}
Node *insertAtKthPosition(Node *head, int k, int data)
{
    if (head == nullptr)
    {
        if (k == 1)
        {
            return head = new Node(data);
        }
    }
    if (k == 1)
    {
        Node *newNode = new Node(data, head);
        // head = newNode;
        return newNode;
    }
    Node *temp = head;
    int cnt = 0;

    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k - 1) // one before kth element
        {
            Node *newNode = new Node(data);
            newNode->next = temp->next; // temp is pointing to one element before kth element
            temp->next = newNode;
            break;
        }

        temp = temp->next;
    }
    return head;
}
Node *insertBeforeValueX(Node *head, int val, int data)
{
    // gauranteed value x is there in LL
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->data == val) // if value is at head
    {
        Node *newNode = new Node(data, head);
        // head = newNode;
        return newNode;
    }
    Node *temp = head;

    while (temp->next != nullptr)
    {

        if (temp->next->data == val)
        {
            Node *newNode = new Node(data);
            newNode->next = temp->next; // temp is pointing to one element before kth element
            temp->next = newNode;
            break;
        }

        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArrToLL(arr);
    head = insertAtHead(head, 0);            // adding at head; 0 1 2 3 4 5
    head = insertAtTail(head, 6);            // adding at end 0 1 2 3 4 5 6
    head = insertAtKthPosition(head, 3, 80); // adding at 3rd place 0 1 80 2 3 4 5 6
    head = insertBeforeValueX(head, 80, 90);
    // Traversal and length of LL
    printLL(head);
}
