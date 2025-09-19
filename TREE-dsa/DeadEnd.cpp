

class Solution {
  public:
   bool Dead(Node *root, int lower , int upper){
        if(root==NULL) return 0;
         if(!root->left &&!root->right){
             if(root->data-lower == 1 &&  upper-root->data==1){
                 return 1;
             }else
                 return 0;
         }
           return   Dead(root->left,lower,root->data) || Dead(root->right,root->data,upper);
         
   }
    bool isDeadEnd(Node *root) {
        // Code here
           return Dead(root,0,INT_MAX);
    }
};


//  nakuri 
bool solve(TreeNode<int>* root , int minvalue , int maxvalue ){
      if(root==NULL) return  false ;
       if(minvalue == maxvalue) return true;

         return solve(root->left , minvalue , root->data-1) || solve(root->right,root->data+1,maxvalue);
  }


bool isDeadEnd(TreeNode<int>* root) {
   return solve(root,1,INT_MAX);
}