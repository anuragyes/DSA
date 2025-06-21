/*class Solution {
public:
    void Lview(TreeNode* root, int level, vector<int>& ans) {
        if (root == NULL)
            return;

        if (level == ans.size())
            ans.push_back(root->val);

        Lview(root->left, level + 1, ans);
        Lview(root->right, level + 1, ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return 0;
        Lview(root, 0, ans);
        int n = ans.size();
        return ans[n - 1];
    }
};*/