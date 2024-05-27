#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/* calculates the size of each connected component of 1's in a grid and keeps track of the frequency of these sizes.*/
// This function will return the number of connected cells around the starting [i,j]
int dfs(vector<vector<int>> &visited, vector<vector<int>> &grid, int i, int j)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size())
    {
        return 0; // If we go out of the matrix, then no connected cell
    }

    // If already visited or is marked as 0, return
    if (visited[i][j] || grid[i][j] == 0)
    {
        return 0;
    }

    visited[i][j] = 1;

    // Travel on the connected cells
    int connectedCells = 1;
    connectedCells += dfs(visited, grid, i + 1, j);
    connectedCells += dfs(visited, grid, i - 1, j);
    connectedCells += dfs(visited, grid, i, j + 1);
    connectedCells += dfs(visited, grid, i, j - 1);
    return connectedCells;
}

// This function will return the frequency of each size of a connected grid present in the matrix
unordered_map<int, int> findFrequency(vector<vector<int>> &grid)
{
    unordered_map<int, int> ans;
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                // Count the number of cells in this connected grid
                // and update its size in the hashmap
                int count = dfs(visited, grid, i, j);
                ans[count]++;
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> grid{
        {1, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
    };

    vector<int> queries{6, 1, 8, 2};

    unordered_map<int, int> frequencyCount = findFrequency(grid);

    for (int i = 0; i < queries.size(); i++)
    {
        cout << "no. of component of size " << queries[i] << " : " << frequencyCount[queries[i]] << endl;
    }
}