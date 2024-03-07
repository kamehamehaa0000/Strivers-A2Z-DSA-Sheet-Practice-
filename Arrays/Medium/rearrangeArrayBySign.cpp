#include <bits/stdc++.h>
using namespace std;
vector<int> RearrangebySign(vector<int> &arr, int n)
{ // Variant 1- for even no. of + and -
    /*brute force
    vector<int> positive;
    vector<int> negative;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            negative.push_back(arr[i]);
        }
        else
        {
            positive.push_back(arr[i]);
        }
    }
    for (int i = 0; i < n / 2; i++)
    {
        arr[2 * i] = positive[i];
        arr[2 * i + 1] = negative[i];
    }*/

        /* optimal
    vector<int> ans;
    int positive = 0;
    int negative = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            ans[negative] = arr[i];
            negative += 2;
        }
        else
        {
            ans[positive] = arr[i];
            positive += 2;
        }
    }
    return ans;*/
    /*VARIANT 2 for uneven no. of + and -
     */

    vector<int> positive;
    vector<int> negative;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            negative.push_back(arr[i]);
        }
        else
        {
            positive.push_back(arr[i]);
        }
    }
    if (positive.size() > negative.size())
    {
        for (int i = 0; i < negative.size(); i++)
        {
            arr[2 * i] = positive[i];
            arr[2 * i + 1] = negative[i];
        }
        int index = 2 * negative.size();
        for (int i = negative.size(); i < positive.size(); i++)
        {
            arr[index] = positive[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < positive.size(); i++)
        {
            arr[2 * i] = positive[i];
            arr[2 * i + 1] = negative[i];
        }
        int index = 2 * positive.size();
        for (int i = positive.size(); i < negative.size(); i++)
        {
            arr[index] = negative[i];
            index++;
        }
    }
}

int main()
{
    // There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.
    int n = 6;
    vector<int> arr{1, 2, -4, -5, 3, 4};
    RearrangebySign(arr, n);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}