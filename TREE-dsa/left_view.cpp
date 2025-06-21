



//  first method using recursion 


//  void Lview(Node* root , int level , vector<int>&ans){
//        if(root==NULL) return ;
       
//         if(level==ans.size())
//             ans.push_back(root->data);
        
        
//          Lview(root->left,level+1,ans);
//           Lview(root->right,level+1,ans);
         
//  }

// vector<int> leftView(Node *root)
// {

//       vector<int>ans;
//           if(root==NULL) return ans;
//          Lview(root,0,ans);
//           return ans;
     
// }




// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// class node
// {
// public:
//     int data;
//     node *left;
//     node *right;
//     node(int val)
//     {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// //  explain by shraddha didi
// vector<int> leftview(node *root)
// {
//     vector<int> ans;
//     if (root == NULL)
//     {
//         return ans;
//     }
//     queue<node *> q;
//     q.push(root);

//     while (!q.empty())
//     {

//         ans.push_back(q.front()->data);
//         int n = q.size();
//         while (n--)
//         {
//             node *temp = q.front();
//             q.pop();
//             if (temp->left)
//             {
//                 q.push(temp->left);
//             }
//             if (temp->right)
//             {
//                 q.push(temp->right);
//             }
//         }
//     }
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << endl;
//     }
// }

// // left view 
//  void leftview(TreeNode<int> *root,vector<int>&ans,int level){
//   if(root==NULL) return ;
//   if(ans.size()==level){
//       ans.push_back(root->data);
//   }
//    leftview(root->left, ans, level+1);
//    leftview(root->right, ans, level+1);
//  }

// vector<int> getLeftView(TreeNode<int> *root)
// {
//       vector<int>ans;
//       leftview(root,ans,0); // 0 means level 
//        return ans;
// }


//   right view problem 
// class Solution
// {
//     public:
    
//      void rightview(Node* root, int level , vector<int>&ans){
//            if(root==NULL){
//                 return ;
//            }
//            if(ans.size()==level){
//                ans.push_back(root->data);
//            }
//             rightview(root->right,level+1,ans);
//              rightview(root->left,level+1,ans);
//      }
//     //Function to return list containing elements of right view of binary tree.
//     vector<int> rightView(Node *root)
//     {
//         vector<int>ans;
//         rightview(root, 0 , ans);
//         return  ans;
//     }
// };



// int main()
// {

//     node *root = new node(3);
//     root->left = new node(9);
//     root->right = new node(20);

//     root->right->left = new node(15);
//     root->right->right = new node(7);
//     leftview(root);

//     return 0;
// }