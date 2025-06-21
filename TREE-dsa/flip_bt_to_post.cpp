/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
    
      vector<int>ans;
      int i=0;
    
    
       bool dfs(TreeNode* root, vector<int>& arr){
       if(root==NULL)  return true;
    
         if(root->val != arr[i]){
             return false;
         }
          i++;
    
    
           if(root->left && root->left->val!=arr[i]){
             ans.push_back(root->val);
             return dfs(root->right,arr) && dfs(root->left,arr);
           }
    
            return dfs(root->left,arr) && dfs(root->right,arr);
       }
        vector<int> flipMatchVoyage(TreeNode* root, vector<int>& arr) {
             
             if(dfs(root,arr))  return ans;
              return {-1};
        }
    };