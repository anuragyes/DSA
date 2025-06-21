

#include <iostream>
#include <queue>
using namespace std;



class Solution{
  public:
  
   void postorder(Node* root, vector<int>&ans, int &index){
        if(root==NULL){
             return ;
        }
         postorder(root->left,ans, index);
         postorder(root->right,ans, index);
         
         root->data = ans[index];
         index++;
   }
  
     void inorderT(Node* root, vector<int>&ans){
            if(root==NULL){
                 return ;
            }
             inorderT(root->left, ans);
              ans.push_back(root->data);
              inorderT(root->right, ans);
     }
    void convertToMaxHeapUtil(Node* root)
    {
        //  this question  solved in two step 
        // first find inorder traversal 
        // second put element in the form of postorder traversal 
         vector<int>ans;
          inorderT(root,ans);
        //  post order traversal 
        
        int index = 0 ;
         postorder(root,ans,index);
    }    
};