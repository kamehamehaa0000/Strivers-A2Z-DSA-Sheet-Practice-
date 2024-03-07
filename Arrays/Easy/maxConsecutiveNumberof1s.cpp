#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int> &nums)
{
    int maxi = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            count++;
            maxi = max(maxi, count);
        }
        else
        {
            count = 0;
        }
    }
    return maxi;
    /* xor


    */
}
int main()
{
    int n = 5;
    int arr[n] = {1, 1, 1, 4, 1};

    return 0;
}