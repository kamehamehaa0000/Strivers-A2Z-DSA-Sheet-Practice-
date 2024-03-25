#include <stack>
#include <iostream>

using namespace std;
/*BRUTE FORCE
string reverseWords(string s)
{
    stack<string> st;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            ans += s[i];
        }
        else
        {
            if (!ans.empty())
            {
                st.push(ans);
                ans = "";
            }
        }
    }

    // Push the last word into the stack
    if (!ans.empty())
    {
        st.push(ans);
    }

    // Pop words from the stack and form the reversed string
    ans = "";
    while (!st.empty())
    {
        ans += st.top() + " ";
        st.pop();
    }

    // Remove the trailing space
    if (!ans.empty())
    {
        ans.pop_back();
    }

    return ans;
}*/
/*Optimal only in spce due to removing stacks*/
string reverseWords(string s)
{
    int i = 0;              // low or starting pointer
    int j = s.length() - 1; // high or ending pointer
    string ans = "";
    string temp = "";
    // removing starting spaces
    while (i < j && s[i] == ' ')
    {
        i++;
    }
    // removing ending spaces
    while (i < j && s[j] == ' ')
    {
        j--;
    }
    // Iterate the string and keep on adding to form a word
    // If an empty space is encountered then add the current word to the result

    while (i <= j)
    {
        char ch = s[i];
        if (ch != ' ')
        {
            temp += ch;
        }
        else if (ch == ' ')
        {
            if (!temp.empty())
            {
                if (ans != "")
                {
                    ans = temp + " " + ans;
                }
                else
                {
                    ans = temp;
                }
                temp = "";
            }
        }
        i++;
    }
    // If last word(temp) not an empty string then add to the result
    if (temp != "")
    {
        if (ans != "")
        {
            ans = temp + " " + ans;
        }
        else
        {
            ans = temp;
        }
    }

    return ans;
}
int main()
{
    string input = "  Hello   World   ";
    string reversed = reverseWords(input);

    cout << "Original: ." << input << "." << endl;
    cout << "Reversed: ." << reversed << "." << endl;

    return 0;
}
