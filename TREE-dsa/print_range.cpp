// #include <vector>
// #include <algorithm>
// #include <math.h>
// using namespace std;
// #include <iostream>
// #include <climits>

// // Definition for a binary tree node.



// // Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };


// class Solution
// {
//     public:
//      int ans ;
//     void find(Node* root,int &k){
//         if(root==NULL){
//             return ;
//         }
//         find(root->right,k);
//         k--;
//         if(k==0){
//             ans=root->data;
//             return ;
//         }
//         find(root->left,k);
//     }
    
//     int kthLargest(Node *root, int K)
//     {
//         find(root,K);
//         return ans;
//     }
// };

