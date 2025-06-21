/*void help(Node *root, int target , bool &ans , int sum){
      if(root==NULL) return ;

     sum = sum + root-> data ;
     if(sum== target && root-> left==NULL && root-> right==NULL){
         ans = true;
         return ;
     }
     help(root-> left , target , ans , sum);
     help(root-> right , target , ans , sum);

 }
class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
         bool ans = false ;
        int sum =0 ;

         help(root , target , ans , sum);
        return ans;
    }
};*/
