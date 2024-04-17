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

class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
ListNode *mergeKLists(vector<ListNode *> &lists)
{

    priority_queue<ListNode *, vector<ListNode *>, compare> pq;

    int k = lists.size();
    if (k == 0)
    {
        return nullptr;
    }
    for (int i = 0; i < k; i++)
    {
        if (lists[i] != nullptr)
        {
            pq.push(lists[i]);
        }
    }
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    while (pq.empty() > 0)
    {
        ListNode *smallest = pq.top();
        pq.pop();

        if (head == nullptr)
        {
            head = smallest;
            tail = smallest;
            if (head->next != nullptr)
            {
                pq.push(tail->next);
            }
        }
        else
        {
            tail->next = smallest;
            tail = smallest;
            if (tail->next != nullptr)
            {
                pq.push(tail->next);
            }
        }
    }
    return head;
}