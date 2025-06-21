/*class Solution {
public:
    int maxLevelSum(TreeNode* root) {
      if (root == nullptr) return 0;

        int maxSum = INT_MIN;
        int maxLevel = 1;
        int currentLevel = 1;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int sum = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (sum > maxSum) {
                maxSum = sum;
                 maxLevel = currentLevel;
            }

            ++currentLevel;
        }

         return maxLevel;
      
    }
};*/