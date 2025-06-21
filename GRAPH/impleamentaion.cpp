#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

// there are two way for representing the graph  1 ajd list and 2 is two D-matrix

//   this is adj  list implemantation

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addedge(int u, int v, bool direction) // u and v are edges 1->2,3 u =2 v= 3 means 1->2 connected 1->3 conected

    {
        //   direction -> 0 means undirected graph
        //   direction -> 1 means directed graph

        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << " enter the number of nodes" << endl;
    cin >> n;
    int m;
    cout << " enter the number of edges" << endl;
    cin >> m;
    graph g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        //    graph creating unordered_map
        g.addedge(u, v, 0);
    }
    g.print();
    return 0;
}
