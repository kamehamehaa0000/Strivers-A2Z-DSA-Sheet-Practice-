#include <bits/stdc++.h>
using namespace std;

/*
Rules -
    1. Every row should have one Queen
    2. Every column should have one Queen
    3. No two queens can attack each other
*/

bool isSafe(int row, int col, vector<string> &board, int n)
{
    int dupRow = row;
    int dupCol = col;
    // checking upper left diagonal so row and col both will decrease
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col--;
    }
    // checking for left
    row = dupRow;
    col = dupCol;

    while (col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        col--;
    }
    // checking for lower left diagonal
    row = dupRow;
    col = dupCol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row++;
        col--;
    }
    return true;
}
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    // Base case
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    // recursive call
    for (int i = 0; i < n; i++) // i is row
    {
        if (isSafe(i, col, board, n))
        {
            board[i][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[i][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    // creating empty board
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    // calling recursive function
    solve(0, board, ans, n);
    return ans;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*Optimised approach using hashing and recursion*/

void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftrow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
            board[row][col] = '.';
            leftrow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    // declaring hashmaps
    vector<int> leftrow(n, 0);
    vector<int> upperDiagonal(2 * n - 1, 0);
    vector<int> lowerDiagonal(2 * n - 1, 0);
    solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
    return ans;
}