#include <bits/stdc++.h>
using namespace std;
/*
1. Top-Left: (-1, -1)
2. Top: (-1, 0)
3. Top-Right: (-1, +1)
4. Right: ( 0, +1)
5. Bottom-Right: (+1, +1)
6. Bottom: ( 1, 0)
7. Bottom-Left: ( 1, -1)
8. Left: ( 0, -1)

int delRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int delCol[] = {-1, 0, 1, 1, 1, 0, -1, -1};
*/
// https://leetcode.com/problems/number-of-islands/description/

class Solution
{
private:
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1')
        {
            return;
        }

        grid[i][j] = '2';

        int delRow[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delCol[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

        for (int k = 0; k < 8; k++)
        {
            int nrow = i + delRow[k];
            int ncol = j + delCol[k];
            dfs(nrow, ncol, grid);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int cnt = 0;

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

/*leetcode one*/
class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1')
        {
            return;
        }

        grid[i][j] = '2';

        for (int k = 0; k < 4; k++)
        {
            int nrow = i + delRow[k];
            int ncol = j + delCol[k];
            dfs(grid, nrow, ncol);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
