#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &arr)
{
    /*Brute force
    O(N!*N) -time compelxity at minimum
    Step 1: Find all possible permutations of elements present and store them.
    Step 2: Search input from all possible permutations.
    Step 3: Print the next permutation present right after it
    */

    /*solution 1 using STL

    next_permutation(arr.begin(), arr.end());
    return arr;

    */

    /*solution 2 - Optimal solution
    intuition - O(N^3)
    1. search for dip or Longer prefix match (figure out break point) a[i]<a[i+1]
    2. stay close to break point (take slightly closer element to break point)
    */
    int n = arr.size();
    int index = -1;
    // Step 1 - finding  dip or break point
    for (int i = n - 2; i > 0; i--)
    {
        if (arr[i] < arr[i + 1])
        { // index i is the break point
            index = i;
            break;
        }
    }
    // If break point does not exist:
    if (index == -1)
    {
        // reverse the whole array:
        reverse(arr.begin(), arr.end());
        return arr;
    }
    // Step 2: Find the next greater element but closest greater and not greatest and swap it with arr[ind]:
    for (int i = n - 1; i > index; i--)
    {
        if (arr[i] > arr[index])
        {
            swap(arr[i], arr[index]);
            break;
        }
    }
    // Step 3: reverse the right half:
    reverse(arr.begin() + index + 1, arr.end());
    return arr;
}

int main()
{
    vector<int> A = {3, 2, 1};
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << "]";
    return 0;
}