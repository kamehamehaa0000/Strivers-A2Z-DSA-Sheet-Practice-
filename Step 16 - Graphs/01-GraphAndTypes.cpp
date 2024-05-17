#include <bits/stdc++.h>
using namespace std;

/* Problem statement
Given an integer n representing number of vertices.
Find out how many undirected graphs (not necessarily connected)
can be constructed out of a given n number of vertices.
*/
class Solution
{
    static long count(int n)
    {
        // n * (n-1) --> for every n vertex we can connect n-1 other vertex
        //(consider self edge not exist)
        //(n*(n-1)) / 2 --> divide by 2 to remove the double-counting each edge
        //(since edges are undirected).
        // so we get total no. of possible edge count
        // return 2^count reason pick or notpick (connect / disconnect each vertex)

        return 1L << ((n * (n - 1)) / 2);
    }
};