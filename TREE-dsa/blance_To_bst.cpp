/*class Solution {
public:
    TreeNode* inorderToBst(int start, int end, vector<int>& ans) {
        //  base case
        if (start > end)
            return NULL;

        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(ans[mid]);
        root->left = inorderToBst(start, mid - 1, ans);
        root->right = inorderToBst(mid + 1, end, ans);
        return root;
    }
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return inorderToBst(0, ans.size() - 1, ans);
    }
};*/