    // this is best and understandable code 

    class Solution {
        public:
        
           int height (TreeNode* root){
             if(root==NULL)  return 0;
        
              return 1+max(height(root->left),height(root->right));
           }
            TreeNode* subtreeWithAllDeepest(TreeNode* root) {
                if (root == NULL)
                    return NULL;
        
                int leftheight = height(root->left);
                int rightheight = height(root->right);
                if (leftheight == rightheight) {
                    return root;
                }
        
                if (leftheight > rightheight) 
                    return subtreeWithAllDeepest(root->left);
                 else 
                    return subtreeWithAllDeepest(root->right);
                
            }
        };
//   difficult to understand 
class Solution {
    public:
        pair<int, TreeNode*> dfs(TreeNode* root) {
            if (!root) return {0, nullptr};
    
            auto left = dfs(root->left);
            auto right = dfs(root->right);
    
            if (left.first > right.first)
                return {left.first + 1, left.second};
            else if (left.first < right.first)
                return {right.first + 1, right.second};
            else
                return {left.first + 1, root};
        }
    
        TreeNode* subtreeWithAllDeepest(TreeNode* root) {
            return dfs(root).second;
        }
    };

    