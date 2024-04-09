#include <bits/stdc++.h>
using namespace std;
/*
// brute force gives TLE
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    if (nums.empty() || k == 0)
    {
        return ans;
    }

    for (int i = 0; i <= nums.size() - k; i++)
    {
        int maxi = nums[i];
        for (int j = i; j < i + k; j++)
        {
            maxi = max(nums[j], maxi);
        }
        ans.push_back(maxi);
    }
    return ans;
}*/

/*Optimal using dequeue*/
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;
    // maintain decreasing order
    for (int i = 0; i < nums.size(); i++)
    {
        // if front is out of bound of current window
        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }
        // if dqback is smaller than current element
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        // if we reached the end of current window add front of dq to ans
        if (i >= k - 1)
        {
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}

/*
1.Maintaining a decreasing order deque: The algorithm maintains a deque dq, which stores indices of elements in nums. This deque always maintains a decreasing order of elements from front to back. This ensures that the maximum element in the current window is always at the front of the deque.

2. Iterating through the elements: The algorithm iterates through each element of the input vector nums.

3.Removing elements outside the window: At each iteration, if the front element of the deque dq is the starting index of the current window (i.e., i - k), it means that this element is outside the current window. So, it removes this element from the front of the deque.

4.Maintaining decreasing order and updating the deque: The algorithm then checks if the current element (nums[i]) is greater than the elements at the back of the deque. If so, it removes those elements from the back of the deque because they cannot be the maximum element in the current or any subsequent windows. This step ensures that the deque maintains the decreasing order.

5.Adding current element index to the deque: After the removal of unnecessary elements, the algorithm adds the index of the current element to the back of the deque.

6.Updating the result vector: If the algorithm has processed at least k elements (i.e., it has reached the end of the first window), it adds the maximum element of the current window (which is at the front of the deque) to the result vector ans.*/