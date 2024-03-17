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
/*Brute force
ListNode *sortList(ListNode *head)
{
    ListNode *temp = head;
    vector<int> arr;
    while (temp != nullptr)
    {
        arr.push_back(temp->val);
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    temp = head;
    int i = 0;
    while (temp != nullptr)
    {
        temp->val = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}*/

/*Optimal mergesort*/
ListNode *merge(ListNode *list1, ListNode *list2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val <= list2->val)
        {
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;
        }
        else if (list1->val > list2->val)
        {
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }
    }
    if (list2 != nullptr)
    {
        temp->next = list2;
    }
    else if (list1 != nullptr)
    {
        temp->next = list1;
    }
    return dummy->next;
}
ListNode *findMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next; // not head cause we need slow to stop at fist middle in case of even length
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *sortList(ListNode *head)
{
    // Base Case
    if (head->next == nullptr || head == nullptr)
    {
        return head;
    }
    // creating left and right LL
    ListNode *middle = findMiddle(head);
    ListNode *leftHead = head;
    ListNode *rightHead = middle->next;
    middle->next = nullptr;
    leftHead = sortList(leftHead);
    rightHead = sortList(rightHead);
    return merge(leftHead, rightHead);
}