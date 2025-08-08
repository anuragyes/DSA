class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> Indegree(numCourses, 0);

        // Build adjacency list and indegree array
        for (auto element : prerequisites) {
            int u = element[0];
            int v = element[1];
            adj[v].push_back(u);
            Indegree[u]++;
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (Indegree[i] == 0)
                q.push(i);
        }

        int count = 0;  // To count processed nodes

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto neighbor : adj[node]) {
                Indegree[neighbor]--;
                if (Indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If all courses are processed, return true
        return count == numCourses;
    }
};
