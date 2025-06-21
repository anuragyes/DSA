/*class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
         if (!root) return true; // Handle empty tree

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            int prevValue = (level % 2 == 0) ? INT_MIN : INT_MAX;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Check the current level's constraints
                if ((level % 2 == 0 && (node->val % 2 == 0 || node->val <= prevValue)) ||
                    (level % 2 == 1 && (node->val % 2 != 0 || node->val >= prevValue))) {
                    return false;
                }

                prevValue = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level++;
        }
        return true;
    }
};*/


/*A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.*/