#include <iostream>
#include <stack>
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
//   there are three case
//    1 when delete key is leaf node
//    2 when delete key is single child .
//    3  when delete key is two child  left or right

node *inorderSuccesor(node *root)
{
    node *current = root;

    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

node *deletenode(node *root, int key)
{

    //    search key for deletetion
    if (key < root->data)
    {
        root->left = deletenode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletenode(root->right, key);
    }
    else
    {
        //  finally we are at key point
        //  case 1
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        //  case 2
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        //    case third
        node *temp = inorderSuccesor(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

int main()
{

    node *root = new node(100);
    root->left = new node(20);
    root->right = new node(200);
    root->left->left = new node(10);
    root->left->right = new node(30);
    root->right->left = new node(150);
    // deletenode();

    return 0;
}