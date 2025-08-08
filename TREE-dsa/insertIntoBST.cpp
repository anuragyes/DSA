// Insert into a Binary Search Tree  
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    TreeNode* build(vector<int>& ans, int start, int end) {

        if (start > end)
            return NULL;

        int mid = start + (end - start) / 2;

        TreeNode* node = new TreeNode(ans[mid]);

        node->left = build(ans, start, mid - 1);
        node->right = build(ans, mid + 1, end);

        return node;
    };

    TreeNode* insertIntoBST(TreeNode* root, int val) {

        //  optimal code
        if (!root) {
            return new TreeNode(val);
        }

        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else { // val > root->val
            root->right = insertIntoBST(root->right, val);
        }

        return root;

        //    brute force approch
        /*
        vector<int> ans;
        inorder(root, ans);
        ans.push_back(val);
        sort(ans.begin(), ans.end());

        return build(ans, 0, ans.size() - 1);
        */
    }
};