#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s)
{
    stack<int> left;
    stack<int> star;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            left.push(i);
        }
        else if (s[i] == '*')
        {
            star.push(i);
        }
        // if right parenthesis
        else
        {
            if (!left.empty())
            {
                left.pop();
            }
            else if (!star.empty())
            {
                star.pop();
            }
            else
            {
                return false;
            }
        }
    }

    while (!left.empty())
    {

        if (star.empty())
        {
            return false;
        }
        // check if star is after left or not
        if (star.top() > left.top())
        {
            star.pop();
            left.pop();
        }
        else
        {
            return false;
        }
    }
    return true;
}