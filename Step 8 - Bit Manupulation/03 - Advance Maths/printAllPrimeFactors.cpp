#include <bits/stdc++.h>
using namespace std;
/*
// Brute Force
bool isPrime(int n)
{
    int cnt = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
        }
        if (n / i != i)
        {
            cnt++;
        }
    }
    if (cnt > 2)
    {
        return false;
    }
    else if (cnt == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<int> countPrimes(int n)
{
    vector<int> ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (isPrime(i))
            {
                ans.push_back(i);
            }
            if (n / i != i)
            {
                if (isPrime(n / i))
                {
                    ans.push_back(n / i);
                }
            }
        }
    }
    return ans;
}*/

/*

Sieve of Eratosthenes works by putting all the numbers till ‘N’ as true and checking if the number is prime or not from 2. if it finds that 2 is prime(that, of course, is), then it marks all its multiple as false, and it repeatedly does it till it reaches N(it reduces time by checking if it is true or not).
Initialize an empty array ‘ans’.
Make a new bool vector initialized with true and of size(N+1);
Now make a loop initialized with 2 and till N, and inside the loop, if the prime is true and it is a factor of ‘N’, push it in ‘ans’ array. and also another loop that eliminates all its multiple till n.
Then return the ‘ans’.
vector<int> countPrimes(int n)
{
    vector<bool> isPrime(n, true);
    vector<int> ans;
    // Counting prime numbers less than 'N'.
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i] == true)
        {
            if (n % i == 0)
            {
                ans.push_back(i);
            }
            for (int j = i * 2; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    return ans;
}

*/

/*Optimal approach - school way*/

vector<int> countPrimes(int n)
{
    vector<int> ans;
    for (int i = 2; i * i < n; i++)
    {

        if (n % i == 0)
        {
            ans.push_back(i);
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }
    if (n != 1)
    {
        ans.push_back(n);
    }
    return ans;
}