#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*Brute force
ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    vector<int> arr;
    ListNode *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        arr.push_back(temp->val);
        temp = temp->next->next;
    }
    if (temp != nullptr)
    {
        arr.push_back(temp->val);
    }
    temp = head->next;
    while (temp != nullptr && temp->next != nullptr)
    {
        arr.push_back(temp->val);
        temp = temp->next->next;
    }
    if (temp != nullptr)
    {
        arr.push_back(temp->val);
    }
    temp = head;
    int i = 0;
    while (temp != nullptr)
    {
        temp->val = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}
*/
/*optimal*/
ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *firstEven = head->next;
    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = firstEven;

    return head;
}
