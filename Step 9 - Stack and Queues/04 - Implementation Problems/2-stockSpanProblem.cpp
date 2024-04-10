#include <bits/stdc++.h>
using namespace std;
// brute force solution O(n)
class StockSpanner
{
public:
    vector<int> prices;
    StockSpanner()
    {
        prices = {};
    }

    int next(int price)
    {
        prices.push_back(price);
        int days = 1;
        int n = prices.size();
        for (int i = n - 2; i >= 0; i--)
        {
            if (prices[i] <= price)
            {
                days++;
            }
            else
            {
                break;
            }
        }
        return days;
    }
};

/*optimal using monotonic stack*/
class StockSpanner
{
public:
    stack<pair<int, int>> st;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int days = 1;

        while (!st.empty() && st.top().first <= price)
        {
            days = days + st.top().second;
            st.pop();
        }
        st.push({price, days});

        return days;
    }
};