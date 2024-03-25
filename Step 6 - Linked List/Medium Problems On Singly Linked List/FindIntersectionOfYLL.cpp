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
/*Brute Force using hashing
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *temp = headA;
    unordered_map<ListNode *, int> mpp;
    while (temp != nullptr)
    {
        mpp[temp] = 1;
        temp = temp->next;
    }
    temp = headB;
    while (temp != nullptr)
    {
        if (mpp.find(temp) != mpp.end())
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}
*/
/*Better
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr)
    {
        return nullptr;
    }

    ListNode *temp1 = headA;
    ListNode *temp2 = headB;
    int len1 = 0;
    int len2 = 0;

    // Calculate lengths of both lists
    while (temp1 != nullptr)
    {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != nullptr)
    {
        len2++;
        temp2 = temp2->next;
    }

    int diff = abs(len1 - len2);

    // Reset pointers
    temp1 = headA;
    temp2 = headB;

    // Traverse the longer list by 'diff' steps
    if (len1 > len2)
    {
        while (diff--)
        {
            temp1 = temp1->next;
        }
    }
    else
    {
        while (diff--)
        {
            temp2 = temp2->next;
        }
    }

    // Traverse both lists until they intersect
    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1 == temp2)
        {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return nullptr;
}
*/
/*optimal*/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr)
    {
        return nullptr;
    }
    ListNode *temp1 = headA;
    ListNode *temp2 = headB;
    // if any of the pointer reached nullptr send it to head of opposite list
    // to align them vertically
    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if (temp1 == temp2)
        {
            return temp1;
        }
        if (temp1 == nullptr)
        {
            temp1 = headB;
        }
        if (temp2 == nullptr)
        {
            temp2 = headA;
        }
    }
    /*or
    while (temp1 != temp2) {
      temp1 = temp1 == nullptr ? headB : temp1->next;
      temp2 = temp2 == nullptr ? headA : temp2->next;
    }
    */
    return temp1;
}