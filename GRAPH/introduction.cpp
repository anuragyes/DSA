#include <iostream>
#include <vector>
using namespace std;
// undirected graph

int main()
{
    int vertex;
    cout << "enter how many vertex " << endl;
    cin >> vertex;
    int edges;
    cout << "enter how many edges " << endl;
    cin >> edges;

    vector<vector<bool>> Adj(vertex, vector<bool>(vertex, 0));
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        Adj[u][v] = 1;
        Adj[v][u] = 1;
    }

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            cout << Adj[i][j] << " ";
        }
        cout << endl;
    }
}