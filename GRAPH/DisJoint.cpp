#include <istream>
#include <vector>
#include <queue>
using namespace std;

class DisJoint
{
public:
    vector<int> rank(n + 1, 0);
    vector<int> parent(n + 1, 0);

public:
    DisJoint(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i; // Initialize each node as its own parent
        }
    }

    int find(int node)
    {
        //    base case
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = find(parent[node]); // Path compression
    }

    void rank(int u, int v)
    {
        int ult_u = find(u);
        int ult_v = find(v);

        if (ult_u == ult_v) //  same in  component
            return;

        if (rank[ult_u] < rank[ult_v])
        {
            parent[ult_u] = ult_v;
        }
        else if (rank[ult_u] > rank[ult_v])
        {
            parent[ult_v] = ult_u;
        }
        else
        {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }

    void unionSet(int u, int v)
    {
        int parentU = parent(u);
        int parentV = parent(v);

        if (parentU != parentV)
        {
            if (rank[parentU] < rank[parentV])
            {
                parent[parentU] = parentV;
            }
            else if (rank[parentU] > rank[parentV])
            {
                parent[parentV] = parentU;
            }
            else
            {
                parent[parentV] = parentU;
                rank[parentU]++;
            }
        }
    }

    bool find(int u, int v)
    {
        return parent(u) == parent(v);
    }
};

int main()
{
    return 0;
}