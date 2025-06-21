// Step 1: Build the graph
vector<vector<pair<int, int>>> graph(n);
for (auto& r : roads) {
    int u = r[0], v = r[1], t = r[2];
    graph[u].emplace_back(v, t);
    graph[v].emplace_back(u, t);
}

// Step 2: Dijkstra to find shortest time from node 0
vector<long long> dist(n, LLONG_MAX);
vector<int> ways(n, 0);
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

dist[0] = 0;
ways[0] = 1;
pq.push({0, 0});

while (!pq.empty()) {
    auto [time, u] = pq.top();
    pq.pop();

    if (time > dist[u]) continue;

    for (auto& [v, wt] : graph[u]) {
        long long newTime = time + wt;

        if (newTime < dist[v]) {
            dist[v] = newTime;
            ways[v] = ways[u];
            pq.push({newTime, v});
        } else if (newTime == dist[v]) {
            ways[v] = (ways[v] + ways[u]) % MOD;
        }
    }
}

return ways[n - 1];