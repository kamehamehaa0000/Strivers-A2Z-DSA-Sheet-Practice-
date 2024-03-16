#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
/*brute force by updating data values
Node *sortList(Node *head)
{
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt0 = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            cnt0++;
        }
        if (temp->data == 1)
        {
            cnt1++;
        }
        if (temp->data == 2)
        {
            cnt2++;
        }
        temp = temp->next;
    }
    temp = head;
    while (cnt0)
    {
        temp->data = 0;
        cnt0--;
        temp = temp->next;
    }
    while (cnt1)
    {
        temp->data = 1;
        cnt1--;
        temp = temp->next;
    }
    while (cnt2)
    {
        temp->data = 2;
        cnt2--;
        temp = temp->next;
    }
    return head;
}
*/

/*better by updating links */

Node *sortList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *ZeroHead = new Node(-1);
    Node *OneHead = new Node(-1);
    Node *TwoHead = new Node(-1);

    Node *zero = ZeroHead;
    Node *one = OneHead;
    Node *two = TwoHead;

    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else //(temp->data==2)
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = (OneHead->next) ? OneHead->next : TwoHead->next;
    one->next = TwoHead->next;
    two->next = nullptr;

    Node *newHead = ZeroHead->next;
    delete ZeroHead;
    delete OneHead;
    delete TwoHead;
    return newHead;
}