#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
  right(right) {}
  };
 
class Solution {
public:
    //    make adjency list
    void buildAdjList(TreeNode* node, unordered_map<int, vector<int>>& adj) {
        if (!node)
            return;

        if (node->left) {
            adj[node->val].push_back(node->left->val);
            adj[node->left->val].push_back(node->val);
            buildAdjList(node->left, adj);
        }

        if (node->right) {
            adj[node->val].push_back(node->right->val);
            adj[node->right->val].push_back(node->val);
            buildAdjList(node->right, adj);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        //  step first  make adj list using unorder_map
        unordered_map<int, vector<int>> adj;
        buildAdjList(root, adj);

        //   now second step  using bfs
        unordered_map<int, bool> visited;
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int count = -1;
        while (!q.empty()) {
            int size = q.size();
            count++;
            while (size--) {
                int node = q.front();
                q.pop();

                visited[node] = true;

                for (auto element : adj[node]) {
                    if (!visited[element]) {
                        visited[element] = true;
                        q.push(element);
                    }
                }
            }
        }
        return count;
    }
};