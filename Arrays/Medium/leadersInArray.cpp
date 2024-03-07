

#include <bits/stdc++.h>
using namespace std;
// leaders are element greater that all element to their right
vector<int> printLeaders(int arr[], int n)
{ /*Brute Force

  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
      bool leader = true;
      for (int j = i + 1; j < n; j++)
          if (arr[j] > arr[i])
          {
              leader = false;
              break;
          }
      if (leader)
          ans.push_back(arr[i]);
  }
  return ans;

  */
    /*Optimal solution*/

    // Last element of an array is always a leader,
    // push into ans array.
    vector<int> ans;
    int max = arr[n - 1];
    ans.push_back(max);
    // Start checking from the end whether a number is greater
    // than max no. from right, hence leader.

    for (int i = n - 2; i > 0; i--)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            ans.push_back(max);
        }
    }
    return ans;
}

int main()
{

    // Array Initialization.
    int n = 6;
    int arr[n] = {10, 22, 12, 3, 0, 6};

    vector<int> ans = printLeaders(arr, n);

    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }

    cout << endl;
    return 0;
}