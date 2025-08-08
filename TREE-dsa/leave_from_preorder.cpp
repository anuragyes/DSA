// Compiler: g++    
// Problem: Given a preorder traversal of a binary tree, find all the leaf nodes in the tree.
#include <vector>
using namespace std;    



class Solution {
  public:
    vector<int> ans;
    void fun(vector<int> &preorder){
        vector<int> left,right;
        int n = preorder.size();
        for(int i=1;i<n;i++){
            if(preorder[i] < preorder[0]) left.push_back(preorder[i]);
            else right.push_back(preorder[i]);
        }
        if(left.size() == 0 && right.size() == 0){
            ans.push_back(preorder[0]);
            return;
        }
        if(left.size()) fun(left);
        if(right.size()) fun(right);
    }
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
         int n = preorder.size();
        fun(preorder);
        return ans;
    }
};