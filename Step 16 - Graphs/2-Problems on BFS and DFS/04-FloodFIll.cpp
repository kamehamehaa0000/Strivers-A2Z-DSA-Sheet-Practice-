#include <bits/stdc++.h>
using namespace std;

/*my solution*/
class Solution
{
private:
    void bfs(int sr, int sc, vector<vector<int>> &image, int color)
    {
        int iniColor = image[sr][sc];
        if (iniColor == color)
        {
            return;
        }

        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        const int delrow[4] = {-1, 0, 1, 0};
        const int delcol[4] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nextRow = row + delrow[k];
                int nextCol = col + delcol[k];

                if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && image[nextRow][nextCol] == iniColor)
                {
                    image[nextRow][nextCol] = color;
                    q.push({nextRow, nextCol});
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        bfs(sr, sc, image, color);
        return image;
    }
};

/*Striver's solution i.e using DFS*/
void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int iniColor)
{
    ans[row][col] = newColor;

    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};

    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nextRow = row + delRow[i];
        int nextCol = col + delCol[i];
        if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m)
        { // check for same initial color and unvisited pixel
            if (image[nextRow][nextCol] == iniColor && ans[nextRow][nextCol] != newColor)
            {
                dfs(nextRow, nextCol, ans, image, newColor, iniColor);
            }
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;
    // this time taking copy of original image so space complexity will be O(m*n)
    dfs(sr, sc, ans, image, newColor, iniColor);
    return ans;
}
