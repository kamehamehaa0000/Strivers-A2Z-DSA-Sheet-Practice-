#include <bits/stdc++.h>
using namespace std;

/*bruteforce*/
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});

        vector<string> usedOnLevel; // store the words being currently used on a level during BFS
        usedOnLevel.push_back(beginWord);
        int level = 0;

        vector<vector<string>> ans;

        while (!q.empty())
        {
            vector<string> sequence = q.front();
            q.pop();

            if (sequence.size() > level) // if we have come on next level clear usedOnlevel vector
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }
                usedOnLevel.clear();
            }

            string word = sequence.back();

            if (word == endWord)
            {
                if (ans.size() == 0) // the first sequence where we reached end
                {
                    ans.push_back(sequence);
                }
                else if (ans[0].size() == sequence.size()) // otherwise if of same size then push
                {
                    ans.push_back(sequence);
                }
            }

            for (int i = 0; i < word.size(); i++)
            {
                char originalChar = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    {
                        sequence.push_back(word); // push to sequence
                        q.push(sequence);
                        usedOnLevel.push_back(word); // mark as visited on the level
                        sequence.pop_back();         // remove from vec
                    }
                }
                word[i] = originalChar;
            }
        }
        return ans;
    }
};

/*
OPTIMAL SOLUTION
Intuition
BFS for storing words and their Levels in Map
DFS for traversing back from Endword to BeginWord backtrack

Approach
Firstly, store words and their levels of finding in a Map using BFS.
If we find the endWord in the map then it's a possible sequence of answer.
From the endword do DFS traversal to beginWord
By doing this there will be minimal operations or searching for past sequence, this reduces time.
Base case is, if we find the word matching with beginWord then reverse the sequecne as we are going from back to front.
After adding it in answer reverse again to previous state
Thus, we're able to solve this with less time and space.
*/

class Solution
{

    unordered_map<string, int> mp; //{word,level or rank}
    vector<vector<string>> ans;
    string b;

private:
    void dfs(string word, vector<string> &seq)
    {
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mp[word];
        int size = word.size();

        // backtrack
        for (int i = 0; i < size; i++)
        {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                if (mp.find(word) != mp.end() && mp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }

            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);
        mp[beginWord] = 1;
        b = beginWord;
        int size = beginWord.size();

        while (!q.empty())
        {
            string word = q.front();
            int steps = mp[word];
            q.pop();

            if (word == endWord)
            {
                break;
            }

            for (int i = 0; i < size; i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if (st.find(word) != st.end())
                    {
                        q.push(word);
                        st.erase(word);
                        mp[word] = steps + 1;
                    }
                }

                word[i] = original;
            }
        }

        if (mp.find(endWord) != mp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};