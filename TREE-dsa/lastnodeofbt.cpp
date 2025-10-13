/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::lastNode(TreeNode* root) {
    
      queue<TreeNode*>q;
      q.push(root);
       int ans =0;
      
        while(!q.empty()){
             TreeNode* node = q.front();
             q.pop();
             
               if(!node->left && !node->right){
                    ans = node->val;
               }
               
                if(node->left){
                    q.push(node->left);
                }
                
                 if(node->right){
                     q.push(node->right);
                 }
             
              
        }
         return ans;
}
You are given the root of a complete binary tree A.

You have to return the value of the rightmost node in the last level of the binary tree.

Try to find a solution with a better time complexity than O(N).