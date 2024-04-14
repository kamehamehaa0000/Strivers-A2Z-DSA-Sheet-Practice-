#include <bits/stdc++.h>
using namespace std;

int main()
{
    // maxHeap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    cout << "size: " << pq.size() << endl;

    // minHeap

    priority_queue<int, vector<int>, greater<int>> minPq;
    minPq.push(4);
    minPq.push(2);
    minPq.push(5);
    minPq.push(3);
    while (!minPq.empty())
    {
        cout << minPq.top() << endl;
        minPq.pop();
    }
    cout << "size: " << pq.size() << endl;
}