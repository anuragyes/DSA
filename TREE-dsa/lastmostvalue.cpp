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


