








/*class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int dfs(Node* root){
        if(!root){
            return 0;
        }
        
           int tmp = root->data;
        
        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);
        
      
        
        root->data = leftSum + rightSum;
      
        return tmp + leftSum + rightSum ;
        
    }
    void toSumTree(Node *node)
    {
       dfs(node);
    }
};*/