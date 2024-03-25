#include <bits/stdc++.h>
using namespace std;
/*Brute Force Solution
int countSubStrings(string str, int k)
{
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = i + 1; j < str.size() + 1; j++)
        {
            string sub = str.substr(i, j - i);
            unordered_map<char, int> mpp;
            for (int k = 0; k < sub.size(); k++)
            {

                if (mpp.find(sub[k]) != mpp.end())
                {
                    mpp[sub[k]] += 1;
                }
                else
                {
                    mpp[sub[k]] = 1;
                }
            }
            if (mpp.size() == k)
            {
                count++;
            }
        }
    }
    return count;
}
*/

/*Better
int countSubStrings(string str, int k)
{
    int count = 0;
    vector<int> freq(26);
    for (int i = 0; i < str.size(); i++)
    {
        int distinctCount = 0;
        fill(freq.begin(), freq.end(), 0);

        for (int j = i; j < str.length(); j++)
        {
            if (freq[str[j] - 'a'] == 0)
            {
                distinctCount++;
            }

            freq[str[j] - 'a']++;

            if (distinctCount == k)
            {
                count++;
            }
        }
    }

    return count;
}*/
/*OPTIMAL solution using sliding window*/
/*Intuition :
By subtracting the count of substrings with at most 2 different characters
from the count of substrings with at most 3 different characters, you are
essentially removing the substrings that have at most 2 different characters
from the total count of substrings with at most 3 different characters.
This subtraction leaves you with the substrings that have exactly 3 different characters

so Number of substrings with exactly k different characters = Count(at most k) - Count(at most k-1)

*/
int countSubstrAtMostK(string str, int k)
{
    int i = 0, j = 0, currentCount = 0, result = 0;
    vector<int> count(26, 0); // Array to store count of characters.

    while (j < str.size())
    {
        int index = str[j] - 'a'; // index of current character

        count[index] += 1; // increment count of current character
        if (count[index] == 1)
        {
            currentCount++;
        }
        // decrement count and increase Ith pointer
        while (currentCount > k)
        {
            count[str[i] - 'a']--;
            if (count[str[i] - 'a'] == 0)
            {
                currentCount--;
            }
            i++;
        }
        result += (j - i + 1);
        j++;
    }
    return result;
}
int countSubStrings(string str, int k)
{
    int ans = countSubstrAtMostK(str, k) - countSubstrAtMostK(str, k - 1);
    return ans;
}
int main()
{
    string s = "aacfssa";

    cout << countSubStrings(s, 3);
    return 0;
}