/*class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {

        if (root == NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);
  int last = 0;
        while (!q.empty()) {
             last = 0;
            int levelsum = 0;
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* ptr = q.front();
                q.pop();
                levelsum = levelsum + ptr->val;

                if (ptr->left)
                    q.push(ptr->left);
                if (ptr->right)
                    q.push(ptr->right);
            }
            last = levelsum;
        }
         return last;
    }
    

};*/