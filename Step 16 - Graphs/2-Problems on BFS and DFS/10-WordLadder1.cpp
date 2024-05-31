#include <bits/stdc++.h>
using namespace std;
/* using bfs */
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q; // word,step(ladder length)
        q.push({beginWord, 1});
        unordered_set<string> wordListSet(wordList.begin(), wordList.end());
        wordListSet.erase(beginWord);
        while (!q.empty())
        {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            if (word == endWord)
            {
                return step;
            }

            for (int i = 0; i < word.size(); i++)
            {
                char originalChar = word[i];
                for (int ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (wordListSet.find(word) != wordListSet.end())
                    {
                        wordListSet.erase(word); // remove so you won't go back to it again
                        q.push({word, step + 1});
                    }
                }
                word[i] = originalChar;
            }
        }
        return 0;
    }
};