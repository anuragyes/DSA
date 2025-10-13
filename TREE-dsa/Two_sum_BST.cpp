/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//   using namespace std;
//  #include <vector>
//     // brute force approch 
//    void inorder(TreeNode* root, vector<int>&ans)
//     {
//         if(root==NULL)  return ;
//         inorder(root->left,ans);
//         ans.push_back(root->val);
//         inorder(root->right,ans);
//     }


// int Solution::t2Sum(TreeNode* root, int target) {

    //  brute force approch 
    // vector<int>ans;
       
    //   inorder(root,ans);
    //    if(ans.empty())  return 0;
    //    int start =0;
    //     int end = ans.size()-1;
        
    //       while(start<end){
    //            if(ans[start]+ans[end]==target) {
    //                return 1;
    //            }else if(ans[start]+ans[end]>target){
    //                end--;
    //            }else{
    //                start++;
    //            }
                 
    //       }
          
    //        return 0;
    
// }


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Helper to push leftmost or rightmost path into stack
void pushAll(TreeNode* node, stack<TreeNode*>& stk, bool reverse) {
    while (node) {
        stk.push(node);
        node = reverse ? node->right : node->left;
    }
}

int Solution::t2Sum(TreeNode* A, int B) {
    if (!A) return 0;

    stack<TreeNode*> leftStk, rightStk;

    // Initialize both stacks
    pushAll(A, leftStk, false);  // normal in-order (ascending)
    pushAll(A, rightStk, true);  // reverse in-order (descending)

    while (!leftStk.empty() && !rightStk.empty()) {
        TreeNode* leftNode = leftStk.top();
        TreeNode* rightNode = rightStk.top();

        // Stop if both iterators point to same node
        if (leftNode == rightNode) break;

        int sum = leftNode->val + rightNode->val;

        if (sum == B) return 1;
        else if (sum < B) {
            // Move left iterator forward (next greater)
            leftStk.pop();
            pushAll(leftNode->right, leftStk, false);
        } else {
            // Move right iterator backward (next smaller)
            rightStk.pop();
            pushAll(rightNode->left, rightStk, true);
        }
    }

    return 0;
}

