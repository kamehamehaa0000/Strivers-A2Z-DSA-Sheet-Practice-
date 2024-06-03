#include <bits/stdc++.h>
using namespace std;

/* multisource shortest path algo and also detects neg cycle*/
/*we go to i node to j node via every vertex/node*/
class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1) //-1 cause , ques denotes that no edge is present by -1
                {
                    matrix[i][j] = 1e9;
                }
                if (i == j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        /*floyd warshall algo starts*/
        for (int k = 0; k < n; k++) // for i to j via k
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j],
                                       matrix[i][k] + matrix[k][j]);
                }
            }
        }
        /*floyd warshall algo ends*/

        /*to detect neg cycle
        for (int i = 0; i < n; i++)
        {
            if(matrix[i][i]<0){
                cout<<" neg cylce detected";
            }
        }*/

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1e9)
                {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};