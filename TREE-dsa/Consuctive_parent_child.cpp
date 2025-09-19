/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::consecutiveNodes(TreeNode* root) {
    
     queue<TreeNode*>q;
      int pair =0;
     q.push(root);
      while(!q.empty()){
           TreeNode* node = q.front();
           q.pop();
           
             if(node->left){
                 if(abs(node->val - node->left->val) == 1){
                     pair++;
                 }
                  
                   q.push(node->left);
             }
             
             if(node->right){
                 
                  if(abs(node->val - node->right->val) == 1){
                     pair++;
                 }
                   q.push(node->right);
             }
      }
        return pair;
}



/*Problem Statement (simplified)

You are given a binary tree, and you need to check if it contains a parent-child pair such that their values are consecutive integers.

Consecutive here means:

abs(parent.val - child.val) == 1*/