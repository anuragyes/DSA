#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    double maxAvg = INT_MIN;

    // Helper function returns pair of (sum, count) of nodes in subtree
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int currSum = root->val + left.first + right.first;
        int currCount = 1 + left.second + right.second;

        double currAvg = (double)currSum / currCount;
        maxAvg = max(maxAvg, currAvg);

        return {currSum, currCount};
    }

public:
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return maxAvg;
    }
};

int main() {
    // Example Tree:
    //       5
    //      / \
    //     6   1
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(6);
    root->right = new TreeNode(1);

    Solution sol;
    cout << "Maximum average of any subtree: " << sol.maximumAverageSubtree(root) << endl;

    return 0;
}
