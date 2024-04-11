#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &cardPoints, int k)
{
    int lsum = 0;
    int rsum = 0;
    int maxSum = 0;

    // leftsum of first k elements;
    for (int i = 0; i < k; i++)
    {
        lsum += cardPoints[i];
    }
    maxSum = lsum;

    // reducing the front window size
    int r = cardPoints.size() - 1;
    for (int i = k - 1; i >= 0; i--)
    {
        lsum = lsum - cardPoints[i];
        rsum = rsum + cardPoints[r];
        r--;
        maxSum = max(maxSum, (rsum + lsum));
    }
    return maxSum;
}