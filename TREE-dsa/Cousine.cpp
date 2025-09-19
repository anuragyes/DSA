/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> Solution::solve(TreeNode* root, int B) {
    vector<int> ans;
    if (!root) return ans;

    queue<pair<TreeNode*, int>> q; // {node, parent}
    q.push({root, -1});

    while (!q.empty()) {
        int size = q.size();
        bool found = false;
        vector<pair<TreeNode*, int>> levelNodes;

        while (size--) {
            auto [node, parent] = q.front();
            q.pop();

            if (node->val == B) {
                found = true; // target found at this level
            }

            levelNodes.push_back({node, parent});

            if (node->left) q.push({node->left, node->val});
            if (node->right) q.push({node->right, node->val});
        }

        // If target B was found, collect cousins (same level, different parent)
        if (found) {
            int parentOfB = -1;
            for (auto &p : levelNodes) {
                if (p.first->val == B) {
                    parentOfB = p.second;
                    break;
                }
            }

            for (auto &p : levelNodes) {
                if (p.second != parentOfB && p.first->val != B) {
                    ans.push_back(p.first->val);
                }
            }

            return ans;
        }
    }

    return ans;
}



//  or second method 
 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int targetLevel = -1;
    int parentOfB = -1;
    vector<int> ans;

    void dfs(TreeNode* node, int parent, int level, int B) {
        if (!node) return;

        // If we found the target node B
        if (node->val == B) {
            targetLevel = level;
            parentOfB = parent;
        }
        // If this node is on the same level as B but has a different parent → cousin
        else if (level == targetLevel && parent != parentOfB) {
            ans.push_back(node->val);
        }

        // Recurse to children
        dfs(node->left, node->val, level + 1, B);
        dfs(node->right, node->val, level + 1, B);
    }

    vector<int> solve(TreeNode* root, int B) {
        dfs(root, -1, 0, B);
        return ans;
    }
};
