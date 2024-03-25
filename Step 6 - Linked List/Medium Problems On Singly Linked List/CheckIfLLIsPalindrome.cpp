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

/*Brute force solution
bool isPalindrome(Node *head)
{
    Node *temp = head;
    stack<int> st;

    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (!st.empty())
    {
        if (st.top() == temp->data)
        {
            temp = temp->next;
            st.pop();
        }
        else
        {
            return false;
        }
    }
    return true;
}*/
Node *reverseLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *newHead = reverseLL(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
bool isPalindrome(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    // dividing into two halves
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newHead = reverseLL(slow);
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == newHead->data)
        {
            temp = temp->next;
            newHead = newHead->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    // Create a linked list with
    // values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node *head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Check if the linked list is a palindrome
    if (isPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}