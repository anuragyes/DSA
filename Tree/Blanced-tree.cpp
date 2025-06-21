#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
/*
void preorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
};

void postorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
};
*/
void inorderTraversal(node *root, int &target, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left, target, ans);
    cout << root->data << " ";
    inorderTraversal(root->right, target, ans);

     for(int i=0;i<ans.size()-1;i++){
         cout<<ans[i]<<endl;
     }
}

int isPairPresent(node *root, int target)
{

    vector<int> ans;
    inorderTraversal(root, target, ans);
}
// int height(node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     int leftside = height(root->left);
//     int rightside = height(root->right);
//     int ans = max(leftside, rightside) + 1;
//     return ans;
// }

// int diameterOfBinaryTree(node *root)
// {

//     if (root == NULL)
//     {
//         return 0;
//     }
//     int left = diameterOfBinaryTree(root->left);
//     int right = diameterOfBinaryTree(root->right);
//     int combo = height(root->left) + height(root->right);
//     int ans = max(left, max(right, combo));
//     return ans;
// }

// bool blancedTree(node *root)
// {
//     if (root == NULL)
//     {
//         return true;
//     }
//     bool left = blancedTree(root->left); // left is present or not 
//     bool right = blancedTree(root->right);  // right is present or not  
//     bool diff = abs(height(root->left) - height(root->right)) <= 1;
//     if (left && right && diff)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

int main()
{

    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<< isPairPresent(root,2);
    /*
    cout << "preorderTraversal" << endl;
    preorderTraversal(root);
    cout << endl;
    cout << "postorderTraversal" << endl;
    postorderTraversal(root);
    cout << endl;
    cout << "inorderTraversal" << endl;
    inorderTraversal(root);
    cout << endl;
    cout << "the height og given tree is :" << endl;
    cout << height(root);
    cout << endl;
    cout << "Diameter of given tree is :" << endl;
    cout << diameterOfBinaryTree(root);
    cout << endl;
    cout << " Given tree is blanced tree ? " << endl;
    cout << blancedTree << endl;
*/
    return 0;
}