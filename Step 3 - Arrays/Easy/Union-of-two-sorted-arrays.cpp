#include <bits/stdc++.h>
using namespace std;
vector<int> crrOfArr(int arr[], int brr[], int n, int m)
{ /* bruteForce

  set<int> st;
  for (int i = 0; i < n; i++)
  {
      st.insert(arr[i]);
  }
  for (int i = 0; i < m; i++)
  {
      st.insert(brr[i]);
  }
  vector<int> crr;

  for (auto it : st)
  {
      crr.push_back(it);
  }
  return crr;


  */

    /*
    Optimal
    */
    int i = 0, j = 0; // pointers
    vector<int> crr;  // Uninon vector
    while (i < n && j < m)
    {
        if (arr[i] <= brr[j]) // Case 1 and 2
        {
            if (crr.size() == 0 || crr.back() != arr[i])
                crr.push_back(arr[i]);
            i++;
        }
        else // case 3
        {
            if (crr.size() == 0 || crr.back() != brr[j])
                crr.push_back(brr[j]);
            j++;
        }
    }
    while (i < n) // IF any element left in arr
    {
        if (crr.back() != arr[i])
            crr.push_back(arr[i]);
        i++;
    }
    while (j < m) // If any elements left in brr
    {
        if (crr.back() != brr[j])
            crr.push_back(brr[j]);
        j++;
    }
    return crr;
}
int main()
{
    int n = 5;
    int k = 5;
    int arr[n] = {1, 1, 3, 4, 5};
    int brr[k] = {5, 6, 7, 7, 9};
    vector<int> crr = crrOfArr(arr, brr, n, k); //{1,3,4,5,6,7,9}
    for (int i = 0; i < crr.size(); i++)
    {
        cout << " " << crr[i] << " ";
    }

    return 0;
}