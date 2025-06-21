/*Input:
         4
       /   \
      2     5
     / \   / \
    7   1 2   3
       /
      6
Output:
13
*/

/*

class Solution
{
public:
    void solve(Node* root, int length , int &maxlength, int sum , int &maxSum){
    //   now we are in leaf node
     if(root==NULL)
     {
        //   check the length and sum also
          if(length>maxlength)
          {
              maxlength = length;
              maxSum = sum;
          }else if(length == maxlength)
          {
              maxSum = max(maxSum,sum);
          }
           return ;
     }

            sum = sum + root->data;

             solve(root->left,length+1,maxlength,sum,maxSum);
              solve(root->right,length+1,maxlength,sum,maxSum);


    }
    int sumOfLongRootToLeafPath(Node *root)
    {
         int length = 0 ;
          int maxlength = 0 ;


           int sum = 0 ;
            int maxSum = INT_MIN;

            solve(root,length,maxlength,sum,maxSum);
             return maxSum;
    }
};*/


//  optimal 
/*class Solution{
    public:
    int maxPathSum(Node* root)
    {
         if(!root)   return INT_MIN;
        if (root->left == nullptr && root->right == nullptr)
        return root->data;
        
        int left = maxPathSum(root->left);
        int right = maxPathSum(root->right);
        
        return root->data + max(left, right);
    }
};*/