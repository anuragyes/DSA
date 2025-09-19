#include <bits/stdc++.h>
using namespace std;

class disjointSet {
public:
    vector<int> parent, rank;

    disjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findparent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findparent(parent[node]);
    }

    void ByRank(int u, int v) {
        int up = findparent(u);
        int vp = findparent(v);

        if (up == vp) return;

        if (rank[up] > rank[vp]) {
            parent[vp] = up;
        } else if (rank[up] < rank[vp]) {
            parent[up] = vp;
        } else {
            parent[vp] = up;
            rank[up]++;
        }
    }
};

int Kruskal(int V, vector<vector<int>>& edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return a[2] < b[2];
    });

    disjointSet ds(V);
    int mstCost = 0;

    cout << "Edges in MST:\n";
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (ds.findparent(u) != ds.findparent(v)) {
            ds.ByRank(u, v);
            mstCost += wt;
            cout << u << " -- " << v << " == " << wt << "\n";
        }
    }
    return mstCost;
}

int main() {
    int V = 4; // number of vertices
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int cost = Kruskal(V, edges);
    cout << "Total cost of MST: " << cost << "\n";

    return 0;
}
