



BinaryTreeNode* mergeTrees(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
    // Write your code here.


     if(!root1 && !root2)  return NULL;

      int value = 0;

      if(root1)  value +=root1->data;
      if(root2)  value +=root2->data;


    //   make new node 
    BinaryTreeNode* newroot = new BinaryTreeNode(value);

    newroot->left = mergeTrees(root1 ? root1->left : NULL , root2?root2->left:NULL);

    newroot->right = mergeTrees(root1 ? root1->right : NULL , root2  ? root2->right:NULL);


         return newroot;

}