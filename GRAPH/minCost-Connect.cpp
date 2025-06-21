//   based on minimum spanning tree

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);

        // Build the graph
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0}); // {weight, node}
        vector<bool> visited(n, false);
        int value = 0;

        while (!pq.empty())
        {
            auto [weight, node] = pq.top();
            pq.pop();
            if (visited[node])
                continue;
            visited[node] = true;
            value += weight;

            for (auto &[next, wt] : adj[node])
            {
                if (!visited[next])
                {
                    pq.push({wt, next});
                }
            }
        }

        return value;
    }
};
