#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool BellmanFord(int n, int m, int S, vector<vector<int>> &edges, vector<int> &dist) {
    dist.assign(n + 1, INT_MAX);
    dist[S] = 0;

    // Relax all edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            return false; // negative cycle detected
        }
    }
    return true; // no negative cycle
}

int main() {
    int n = 5, m = 8, S = 1;
    vector<vector<int>> edges = {
        {1, 2, -1},
        {1, 3, 4},
        {2, 3, 3},
        {2, 4, 2},
        {2, 5, 2},
        {4, 2, 1},
        {4, 3, 5},
        {5, 4, -3}
    };

    vector<int> dist;
    if (BellmanFord(n, m, S, edges, dist)) {
        cout << "Shortest distances from source " << S << ":\n";
        for (int i = 1; i <= n; i++) {
            cout << i << ": " << (dist[i] == INT_MAX ? -1 : dist[i]) << "\n";
        }
    } else {
        cout << "Negative weight cycle detected\n";
    }

    return 0;
}
