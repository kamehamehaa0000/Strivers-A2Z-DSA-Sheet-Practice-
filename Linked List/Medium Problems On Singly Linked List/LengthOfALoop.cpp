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
/*Brute force - using hashing
int lengthOfLoop(ListNode *head)
{
    unordered_map<ListNode *, int> mpp;
    ListNode *temp = head;
    int timer = 1;

    while (temp != nullptr)
    {
        if (mpp.find(temp) != mpp.end())
        { // node already visited
            int value = mpp[temp];
            return timer - value;
        }
        mpp[temp] = timer; // storing current node in hashmap
        timer++;
        temp = temp->next;
    }
    return 0;
}*/

/*Optimal using tortoise and hair method*/
int findLen(ListNode *slow, ListNode *fast)
{
    int cnt = 1;
    fast = fast->next;
    while (slow != fast)
    {
        cnt++;
        fast = fast->next;
        slow = slow->next;
    }
    return cnt;
}
int lengthOfLoop(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {

        if (slow == fast)
        {
            return findLen(slow, fast);
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;
}