class Solution {
public:
  

    // Function to add one row at a specific depth
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 1;

        // Traverse the tree until reaching the level just before the desired depth
        while (!q.empty()) {
            int n = q.size();
            level++;

            while (n--) {
                TreeNode* node = q.front();
                q.pop();

                // If we are at the level just before the desired depth
                if (level == depth) {
                    TreeNode* leftChild = node->left;
                    TreeNode* rightChild = node->right;

                    // Insert new nodes
                    node->left = new TreeNode(val);
                    node->right = new TreeNode(val);
										
										
                    node->left->left = leftChild;  // Set the original left child as the left child of the new node
                    node->right->right = rightChild;  // Set the original right child as the right child of the new node
                }

                // Continue to the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // If we have reached the desired depth, we don't need to continue
            if (level >= depth) break;
        }

        return root;
    }
};
