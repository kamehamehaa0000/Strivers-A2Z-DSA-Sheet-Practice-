#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int maxSize)
    {
        parent.resize(maxSize);
        size.resize(maxSize);
        for (int i = 0; i < maxSize; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int v)
    {
        if (v == parent[v])
        {
            return v;
        }
        return parent[v] = findUltimateParent(parent[v]);
    }

    void unionBySize(int a, int b)
    {
        a = findUltimateParent(a);
        b = findUltimateParent(b);
        if (a != b)
        {
            if (size[a] < size[b])
            {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DisjointSet ds(n);
        sort(accounts.begin(), accounts.end());
        unordered_map<string, int> mapMailNode; // {mail:nodenumber or userNumber}

        for (int user = 0; user < n; user++)
        {
            for (int email = 1; email < accounts[user].size(); email++)
            {
                string mail = accounts[user][email];
                // if mail not in mpp, assing user to mail in mpp
                if (mapMailNode.find(mail) == mapMailNode.end())
                {
                    mapMailNode[mail] = user;
                }
                else // if mail is in mpp , union user and mpp user of the mail
                {
                    ds.unionBySize(user, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        for (auto it : mapMailNode)
        {
            string mail = it.first;
            int parent = ds.findUltimateParent(it.second);
            mergedMail[parent].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergedMail[i].size() == 0)
            {
                continue;
            }
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};