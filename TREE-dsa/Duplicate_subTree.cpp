#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
unordered_map<string,int>subCount;

vector<TreeNode<int>*>ans;

string solve(TreeNode<int> *root){
    if(root==NULL) return "#";
     string serial = to_string(root->data)+","+solve(root->left)+","+solve(root->right);
     if(subCount[serial]==1){
         ans.push_back(root);
     }
         subCount[serial]++;
         return serial;
     
}

vector<TreeNode<int>*> duplicate_subtree(TreeNode<int> *root){
    ans.clear();subCount.clear();
    solve(root);
    return ans;
}