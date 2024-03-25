#include <bits/stdc++.h>
using namespace std;
/*bruteForce
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int n = a.size();
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == i)
                cnt++;
        }
        if (cnt == 2)
        {
            repeating = i;
        }
        else if (cnt == 0)
        {
            missing = i;
        }
        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }
    return {repeating, missing};
}
*/

/*better
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int repeating = -1;
    int missing = -1;
    int n = a.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[a[i]] += 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mpp.find(i) == mpp.end())
        {
            missing = i;
        }
        else if (mpp[i] == 2)
        {
            repeating = i;
        }
    }

    return {repeating, missing};
}*/
/*Optimal - using math*/
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    // x -  repeating
    // y - missing
    int n = a.size();
    int sum = 0, sqreSum = 0;
    int nsum = (n * (n + 1)) / 2;
    int sqreNsum = n * (n + 1) * (2 * n + 1) / 6;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        sqreSum += a[i] * a[i];
    }

    int diff1 = sum - nsum;
    // acc. to math x-y = diff    ---equation 1
    int diff2 = sqreSum - sqreNsum;
    // acc. to  (x^2 - y^2) = diff => (x-y)(x+y) =diff  ---equation 2

    // Find X+Y = (X^2-Y^2)/(X-Y):
    diff2 = diff2 / diff1;
    // Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y)
    int x = (diff1 + diff2) / 2;
    int y = x - (diff1);
    return {x, y};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}
