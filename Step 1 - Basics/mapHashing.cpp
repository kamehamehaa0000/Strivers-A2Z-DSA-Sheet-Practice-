#include <bits/stdc++.h>
using namespace std;
// map<key(number) , value(frequency)>
// 0(logN) in ordered map hashing for both number and characters
// O(N) in worst case and 0(1) in average case unordered map ( no. of element in data structure is N)
int main()
{
    int n;
    cin >> n;
    int arr[n];
    map<int, int> hash; // unordered_map <int,int> hash;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hash[arr[i]] += 1; // precomutation
    }

    int q;
    while (q--)
    {
        int number;
        cout << "enter the number ";
        cin >> number;
        cout << "count is : " << hash[number] << " " << endl;
    }

    return 0;
}