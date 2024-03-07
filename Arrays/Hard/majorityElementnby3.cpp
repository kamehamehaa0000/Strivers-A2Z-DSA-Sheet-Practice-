#include <bits/stdc++.h>
using namespace std;
/*Brute force approach
vector<int> majorityElement(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (ans.size() == 0 || ans[0] != arr[i])
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                // counting the frequency of arr[i]
                if (arr[j] == arr[i])
                {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ans.push_back(arr[i]);
        }

        if (ans.size() == 2) // for n/3 majority element max  can be (floor of n/3 )integer
            break;
    }

    return ans;
}
*/
/*Better solution

vector<int> majorityElement(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans;
    map<int, int> mpp; //(element[key] :count[value])

    // least occurrence of the majority element:
    int mini = int(n / 3) + 1;

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++; // storing the elements with its count

        // checking if arr[i] is the majority element
        if (mpp[arr[i]] == mini)
        {
            ans.push_back(arr[i]);
        }
        if (ans.size() == 2)
            break;
    }
    sort(ans.begin(),ans.end())//optional if ans is wanted in sorted order
    return ans;
}
*/
/*optimal*/
vector<int> majorityElement(vector<int> arr)
{
    int n = arr.size();
    int cnt1 = 0;
    int cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && arr[i] != el2)
        {
            cnt1 = 1;
            el1 = arr[i];
        }
        else if (cnt2 == 0 && arr[i] != el1)
        {
            cnt2 = 1;
            el2 = arr[i];
        }
        else if (el1 == arr[i])
        {
            cnt1++;
        }
        else if (el2 == arr[i])
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    // manual check
    vector<int> ans;
    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el1)
        {
            cnt1++;
        }
        if (arr[i] == el2)
        {
            cnt2++;
        }
    }
    int min = (int)(n / 3) + 1; // least occurrence of the majority element:
    if (cnt1 >= min)
    {
        ans.push_back(el1);
    }
    if (cnt2 >= min)
    {
        ans.push_back(el2);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}
