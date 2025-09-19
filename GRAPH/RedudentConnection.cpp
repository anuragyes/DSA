#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class DisJointSet
{
    vector<int> parent, rank;

public:
    DisJointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i; // each node is its own parent
        }
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]); // path compression
    }

    void unionByRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return; // already in same set

        if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        DisJointSet dsu(n);    // make object of class DisJointSet and sent  no of nodes

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            if (dsu.findParent(u) == dsu.findParent(v))
            {
                return edge; // already connected → redundant
            }
            dsu.unionByRank(u, v);
        }
        return {};
    }
};
