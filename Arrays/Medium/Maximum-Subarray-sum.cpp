// Kadane algo
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n)
{
    /*
    Brute force

    O(N^3)

    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            maxi = max(sum, maxi);
        }
    }
    return maxi;

    */
    /*Better
    O(N^2)
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxi = max(sum, maxi);
        }
    }
    return maxi;*/

    // Optimal - Kadane Algo
    // O(N)
    /*steps
    Intuition => A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.
    Approach:
    The steps are as follows:

    1.We will run a loop(say i) to iterate the given array.
    2.Now, while iterating we will add the elements to the sum variable and consider the maximum one.
    3.If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer.

    */
    long long maxi = LONG_MIN;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    if (maxi < 0)
    {
        return 0;
    }
    return maxi;
}
void printSubarrayMaxSum(int arr[], int n)
{
    // for follow up question -  print the sub array with max sum
    long long maxi = LONG_MIN;
    long long sum = 0;
    int ansStart = -1;
    int ansEnd = -1;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = max(sum, maxi);
            ansEnd = i;
            ansStart = start;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }

    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]";
}
int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    printSubarrayMaxSum(arr, n);
    return 0;
}
