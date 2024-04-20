#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    // create two heaps - one will be max and one will be min
    priority_queue<int> smaller;                           // max heap will store smaller elements
    priority_queue<int, vector<int>, greater<int>> larger; // min heap will store larger elements

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        // initially push the num into smaller
        smaller.push(num);

        // if largest element of smaller is greater than the smallest element of larger,
        // then push the top of smaller into larger

        if (!smaller.empty() && !larger.empty() && smaller.top() > larger.top())
        {
            int val = smaller.top();
            smaller.pop();
            larger.push(val);
        }

        // if the size of smaller is greater than larger by 2
        // then push the top of smaller into larger

        if (smaller.size() > larger.size() + 1)
        {
            int val = smaller.top();
            smaller.pop();
            larger.push(val);
        }

        // if the size of larger is greater than smaller by 2
        // then push the top of larger into smaller

        else if (larger.size() > smaller.size() + 1)
        {
            int val = larger.top();
            larger.pop();
            smaller.push(val);
        }
    }

    double findMedian()
    {
        // If even
        if (smaller.size() == larger.size())
        {
            return (double(smaller.top()) + double(larger.top())) / 2;
        }
        // if odd
        // if smaller is bigger
        else if (smaller.size() == larger.size() + 1)
        {
            return double(smaller.top());
        }
        // if larger is bigger
        else
        {
            return double(larger.top());
        }
    }
};