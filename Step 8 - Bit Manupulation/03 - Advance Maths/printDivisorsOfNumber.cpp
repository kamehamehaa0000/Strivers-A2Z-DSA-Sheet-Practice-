#include <bits/stdc++.h>
using namespace std;
int *printDivisors(int n, int &size)
{
    int *arr = new int[n];
    int index = 0;
    for (int i = 0; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            arr[index++] == i;
            if (n / i != i)
            {
                arr[index++] == n / i;
            }
        }
    }
    return arr;
}
