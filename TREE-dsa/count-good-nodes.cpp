/*Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

 

*/


/*class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode* node, int maxVal) {
        if (!node) return 0;

        int goodNodeCount = 0;
        if (node->val >= maxVal) {
            goodNodeCount = 1;
            maxVal = node->val;
        }

        goodNodeCount += dfs(node->left, maxVal);
        goodNodeCount += dfs(node->right, maxVal);

        return goodNodeCount;
    }
};*/