#include <bits/stdc++.h>
using namespace std;

vector<int> swapTwoNum(int a, int b)
{
    a = a ^ b;
    b = a ^ b; // = (a^b)^b = a ;
    a = a ^ b; // = (a^b)^a = b ;
    return {a, b};
}
int main()
{
    vector<int> ans = swapTwoNum(2, 4);

    cout << ans[0] << ' ' << ans[1]; // 4 2
}