/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

  void mirror(Node* root) {
        if (root == nullptr)
        return;

    // Swap left and right subtrees
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror the left and right subtrees
    mirror(root->left);
    mirror(root->right);
    }
    */

