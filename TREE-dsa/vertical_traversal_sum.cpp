/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void findRange(TreeNode* root, int pos, int &left, int &right) {
    if (!root) return;

    left = min(left, pos);
    right = max(right, pos);

    findRange(root->left, pos - 1, left, right);
    findRange(root->right, pos + 1, left, right);
}

vector<int> Solution::verticalSum(TreeNode* root) {
    if (!root) return {};

    int left = 0, right = 0;
    findRange(root, 0, left, right);

    int totalCols = right - left + 1;
    vector<int> ans(totalCols, 0);

    queue<pair<TreeNode*, int>> q;
    q.push({root, -left});  // shift index so no negative index  start from most left  index

    while (!q.empty()) {
        auto [node, col] = q.front();
        q.pop();

        ans[col] += node->val;

        if (node->left) q.push({node->left, col - 1});
        if (node->right) q.push({node->right, col + 1});
    }

    return ans;
}



//   if  use  root first  to add into sum 
void findRange(TreeNode* root, int pos, int &left, int &right) {
    if (!root) return;

    left = min(left, pos);
    right = max(right, pos);

    findRange(root->left, pos - 1, left, right);
    findRange(root->right, pos + 1, left, right);
}

vector<int> Solution::verticalSum(TreeNode* root) {
    if (!root) return {};

    int left = 0, right = 0;
    findRange(root, 0, left, right);

    int totalCols = right - left + 1;
    vector<int> ans(totalCols, 0);

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});  // root at column 0

    while (!q.empty()) {
        auto [node, col] = q.front();
        q.pop();

        // shift index by -left to avoid negative indexing
        ans[col - left] += node->val;

        if (node->left) q.push({node->left, col - 1});
        if (node->right) q.push({node->right, col + 1});
    }

    return ans;
}

