#include <bits/stdc++.h>
using namespace std;
// defination of singly linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*Brute force*/
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *temp1 = list1;
    ListNode *temp2 = list2;
    vector<int> arr;
    while (temp1 != nullptr)
    {
        arr.push_back(temp1->val);
        temp1 = temp1->next;
    }
    while (temp2 != nullptr)
    {
        arr.push_back(temp2->val);
        temp2 = temp2->next;
    }

    if (arr.empty())
    {
        return nullptr;
    }
    sort(arr.begin(), arr.end());
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}
/*Optimal changing links*/
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr)
    {
        return list2;
    }
    if (list2 == nullptr)
    {
        return list1;
    }
    ListNode *t1 = list1;
    ListNode *t2 = list2;
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    while (t1 != nullptr && t2 != nullptr)
    {
        if (t1->val <= t2->val)
        {
            temp->next = t1;
            temp = temp->next;
            t1 = t1->next;
        }
        else if (t1->val > t2->val)
        {
            temp->next = t2;
            temp = temp->next;
            t2 = t2->next;
        }
    }
    if (t2 != nullptr)
    {
        temp->next = t2;
    }
    if (t1 != nullptr)
    {
        temp->next = t1;
    }
    return dummy->next;
}
/*Using recursion*/
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr)
    {
        return list2;
    }

    if (list2 == nullptr)
    {
        return list1;
    }

    if (list1->val <= list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}