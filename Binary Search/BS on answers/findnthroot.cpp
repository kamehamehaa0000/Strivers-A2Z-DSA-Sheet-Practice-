#include <bits/stdc++.h>
using namespace std;
/*BruteForce

// Power exponential method:
long long func(int b, int exp)
{
    long long ans = 1;
    long long base = b;
    while (exp > 0)
    {
        if (exp % 2)
        {
            exp--;
            ans = ans * base;
        }
        else
        {
            exp /= 2;
            base = base * base;
        }
    }
    return ans;
}



int NthRoot(int n, int m)
{
    // Use linear search on the answer space:
    for (int i = 1; i <= m; i++)
    {
        long long val = func(i, n);
        if (val == m * 1ll)
            return i;
        else if (val > m * 1ll)
            break;
    }
    return -1;
}*/
#include <bits/stdc++.h>
using namespace std;

// return 1, if == m:
// return 0, if < m:
// return 2, if > m:
int func(int mid, int n, int m)
{

    // return 1, if == m:
    // return 0, if < m:
    // return 2, if > m:
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m) // for overflow case
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}

int NthRoot(int n, int m)
{
    // Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int n = 3, m = 8;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
