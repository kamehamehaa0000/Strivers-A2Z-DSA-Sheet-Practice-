#include <bits/stdc++.h>
using namespace std;

string oddEven(int N)
{

    if ((N | 1) == N)
    {
        return "odd";
    }
    else
    {
        return "even";
    }
}