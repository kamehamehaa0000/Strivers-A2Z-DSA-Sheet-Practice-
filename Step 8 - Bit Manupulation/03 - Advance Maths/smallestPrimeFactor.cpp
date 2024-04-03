#include <bits/stdc++.h>
using namespace std;
// precomputing the spf or prime factors in order to solve set of queries in constant time later on

vector<int> smallestPrimeFactor(vector<int> queries)
{
    // precomputing spf
    int n = 100; // assuming 100 but will be given in question constraints
    vector<int> sPrimeF(n + 1);
    for (int i = 2; i < sPrimeF.size(); i++)
    {
        sPrimeF[i] = i;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (sPrimeF[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (sPrimeF[j] == j)
                {
                    sPrimeF[j] = i;
                }
            }
        }
    }

    // solving the list of queries
    for (int i = 0; i < queries.size(); i++)
    {
        n = queries[i];
        while (n != 1)
        {
            cout << sPrimeF[n];
            n = n / sPrimeF[n];
        }
    }
}