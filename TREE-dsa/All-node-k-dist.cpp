// All Nodes Distance K in Binary Tree
class Solution
{
public:
    vector<int> result;

    int dfs(TreeNode *node, TreeNode *target, int k)
    {
        if (!node)
            return -1;

        // If this node is the target
        if (node == target)
        {
            subtree_add(node, 0, k);
            return 1;
        }

        int left = dfs(node->left, target, k);
        if (left != -1)
        {
            if (left == k)
                result.push_back(node->val);
            else
                subtree_add(node->right, left + 1, k);
            return left + 1;
        }

        int right = dfs(node->right, target, k);
        if (right != -1)
        {
            if (right == k)
                result.push_back(node->val);
            else
                subtree_add(node->left, right + 1, k);
            return right + 1;
        }

        return -1;
    }

    void subtree_add(TreeNode *node, int dist, int k)
    {
        if (!node)
            return;
        if (dist == k)
        {
            result.push_back(node->val);
            return;
        }
        subtree_add(node->left, dist + 1, k);
        subtree_add(node->right, dist + 1, k);
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        dfs(root, target, k);
        return result;
    }
};

// class Solution {
// public:
//     unordered_map<int, vector<int>> maap;

//     void adjlist(TreeNode* root) {
//         if (!root) return;

//         if (root->left) {
//             maap[root->val].push_back(root->left->val);
//             maap[root->left->val].push_back(root->val);
//             adjlist(root->left);
//         }

//         if (root->right) {
//             maap[root->val].push_back(root->right->val);
//             maap[root->right->val].push_back(root->val);
//             adjlist(root->right);
//         }
//     }

//     void bfs(int start, int k, vector<int>& ans) {
//         unordered_map<int, bool> visited;
//         queue<pair<int, int>> q;  // {node, currentDistance}

//         q.push({start, 0});
//         visited[start] = true;

//         while (!q.empty()) {
//             auto [node, dist] = q.front();
//             q.pop();

//             if (dist == k) {
//                 ans.push_back(node);
//             }

//             if (dist > k) break;    // dont go further

//             for (int neighbor : maap[node]) {
//                 if (!visited[neighbor]) {
//                     visited[neighbor] = true;
//                     q.push({neighbor, dist + 1});
//                 }
//             }
//         }
//     }

//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         vector<int> ans;

//         if (!root || !target) return ans;

//         // Step 1: Build adjacency list
//         adjlist(root);

//         // Step 2: BFS from target node
//         bfs(target->val, k, ans);

//         return ans;
//     }
// };
