#include <bits/stdc++.h>
using namespace std;

// present in both
vector<int> intersectionOfArr(vector<int> A, vector<int> B)
{ /* bruteForce

    vector<int> ans;

    // to maintain visited
    vector<int> visited(B.size(), 0);

    for (int i = 0; i < A.size(); i++)
    {

        for (int j = 0; j < B.size(); j++)
        {

            if (A[i] == B[j] && visited[j] == 0)
            {

                // if element matches and has not been matched with any other before
                ans.push_back(B[j]);
                visited[j] = 1;

                break;
            }

            else if (B[j] > A[i])
                break;
            // because array is sorted , element will not be beyond this
        }
    }

    return ans;

    */

    /*
    Optimal

    */
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (i < A.size() && j < B.size())
    {
        if (A[i] < B[j])
        {
            i++;
        }
        else if (B[j] < A[i])
        {
            j++;
        }
        else // if (A[i] == B[j])
        {
            ans.push_back(A[i]);
            j++;
            i++;
        }
    }
    return ans;
}
int main()
{

    vector<int> arr = {1, 2, 3, 3, 4, 5, 6, 7};
    int n = arr.size();
    vector<int> brr = {3, 3, 4, 4, 5, 8};
    int k = brr.size();
    vector<int> crr = intersectionOfArr(arr, brr); //{1,3,4,5,6,7,9}
    for (int i = 0; i < crr.size(); i++)
    {
        cout << " " << crr[i] << " ";
    }

    return 0;
}