/*class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
      if(root==nullptr){
            return nullptr;
        }
        if(root->val < low){
            return trimBST(root->right,low,high);
        }
        if(root->val > high){
            return trimBST(root->left,low,high);
        }
        root->left=trimBST(root->left,low,high);
        root->right=trimBST(root->right,low,high);
        return root;
    }
};*/


/*Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]*/