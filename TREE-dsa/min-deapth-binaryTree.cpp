// class Solution{
//   public:
//     /*You are required to complete this method*/
// int minDepth(Node *root)
// {
//     if (!root)
//         return INT_MAX;
//     if (!root->left && !root->right)
//         return 1;

//     return 1 + min(minDepth(root->left), minDepth(root->right));
// }
// }
// ;
