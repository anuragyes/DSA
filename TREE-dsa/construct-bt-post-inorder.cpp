/*class Solution {
public:
     // Function to find the index of the element in inorder vector
    int findPosition(const vector<int>& inorder, int element) {
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == element) {
                return i;
            }
        }
        return -1;
    }

    // Recursive function to build the tree
    TreeNode* solve(const vector<int>& postorder, const vector<int>& inorder, int& index, int start, int end) {
        // Base case
        if (start > end)
            return nullptr;
        if (index < 0)
            return nullptr;

        // Create the root node with the current element in postorder
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);

        // Find the index of the current element in inorder
        int position = findPosition(inorder, element);

        // Recursively build the right and left subtrees
        // Note: In postorder, we build right subtree first, then left subtree
        root->right = solve(postorder, inorder, index, position + 1, end);
        root->left = solve(postorder, inorder, index, start, position - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int indexPost = postorder.size() - 1;
        int n = inorder.size() - 1;
        return solve(postorder, inorder, indexPost, 0, n);
    }
};*/