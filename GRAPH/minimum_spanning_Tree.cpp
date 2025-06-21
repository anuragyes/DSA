int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    vector<vector<pair<int, int>>> adj(n);  // node -> {neighbour, weight}

    // Build the adjacency list
    for (auto &it : edges) {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0}); // {weight, node}
    int totalWeight = 0;

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node]) continue;

        visited[node] = true;
        totalWeight += weight;

        for (auto &neighbor : adj[node]) {
            int adjNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (!visited[adjNode]) {
                pq.push({edgeWeight, adjNode});
            }
        }
    }

    return totalWeight;
}
