You are given the root of a binary tree A.
You have to find out the number of parent - child relationship whose values are consecutive numbers.

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
