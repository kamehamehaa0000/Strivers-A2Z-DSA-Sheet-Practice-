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

// deleting the head;
Node *deleteHead(Node *head)
{

    if (head->next == nullptr || head == nullptr)
    {
        free(head);
        return nullptr;
    }
    Node *prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;
    free(prev);

    return head;
}
Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        free(head);
        return nullptr;
    }
    Node *prev = head;
    while (prev->next->next != nullptr)
    {
        prev = prev->next;
    }
    free(prev->next);
    prev->next = nullptr;
    return head;
}
Node *deleteKthNode(Node *head, int k)
{
    if (k == 1) // if k==1 or head
    {
        if (head == nullptr) // if list is empty
        {
            return nullptr;
        }
        // else delete head
        Node *prev = head;
        head = head->next;
        head->back = nullptr;
        prev->next = nullptr;
        prev->back = nullptr;
        free(prev);
        return head;
    }

    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
        {
            Node *prev = temp->back;
            Node *nextNode = temp->next;

            if (prev != nullptr)
            {
                prev->next = nextNode;
            }

            if (nextNode != nullptr)
            {
                nextNode->back = prev;
            }

            temp->next = nullptr;
            temp->back = nullptr;
            free(temp);

            return head;
        }
        temp = temp->next;
    }
    return head;
}
void deleteGivenNode(Node *given)
{
    // given node can't be head
    Node *prev = given->back;
    Node *front = given->next;
    if (front == nullptr) // if node is the last node
    {
        prev->next = nullptr;
        given->back = nullptr;
        free(given);
        return;
    }
    prev->next = front;
    front->back = prev;

    given->next = given->back = nullptr;
    free(given);
    return;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArrToDLL(arr);
    printDLL(head);
    head = deleteHead(head); // 2 3 4 5
    printDLL(head);
    head = deleteTail(head); // 2 3 4
    printDLL(head);
    head = deleteKthNode(head, 2); // 2  4
    printDLL(head);
    deleteGivenNode(head->next); // 2
    printDLL(head);
}