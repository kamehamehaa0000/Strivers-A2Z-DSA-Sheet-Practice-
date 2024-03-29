#include <bits/stdc++.h>
using namespace std;

bool searchNext(vector<vector<char>> &board, string word, int i, int j, int index, int m, int n)
{
    // index reached the end i.e word is found
    if (index == word.size())
    {
        return true;
    }
    // if the current cell is not the character we require and also if i and j are out of board boundry
    if (i < 0 || j < 0 || i == m || j == n || board[i][j] != word[index] || board[i][j] == '*')
    {
        return false;
    }
    char c = board[i][j];
    board[i][j] = '*'; // marking current char to be visited so it can't be traversed later

    bool top = searchNext(board, word, i - 1, j, index + 1, m, n);
    bool bottom = searchNext(board, word, i + 1, j, index + 1, m, n);
    bool right = searchNext(board, word, i, j + 1, index + 1, m, n);
    bool left = searchNext(board, word, i, j - 1, index + 1, m, n);

    board[i][j] = c;                       // undoing the changes made in the board to mark a node visited
    return top || right || bottom || left; // return if any of these is true cause we found the next word
}
bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();
    int index = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == word[index])
            {
                if (searchNext(board, word, i, j, index, m, n))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
