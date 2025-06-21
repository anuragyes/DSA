#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
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

// void predecessor(node *root, int key)
// {
//     int min = INT_MIN;

//     node *curr = root;
//     while (curr->left != NULL)
//     {
//         if (curr->data == key)
//         {
//             break;
//         }
//         if (min < curr->data)
//         {
//             min = curr->data;
//         }
//     }
//     cout << min;
// }

void findPreSuc(node *root, int key)
{
    // Your code goes here
    // node *pre = NULL;
    // node *suc  =NULL;
    // node *keyNode = root;
    // if (keyNode == NULL)
    // {
    //     pre = NULL;
    //     suc = NULL;
    //     return;
    // }

    // while (keyNode != NULL)
    // {
    //     if (keyNode->data == key)
    //     {
    //         break;
    //     }
    //     if (keyNode->data > key)
    //     {
    //         suc = keyNode;
    //         keyNode = keyNode->left;
    //     }

    //     else
    //     {
    //         pre = keyNode;
    //         keyNode = keyNode->right;
    //     }
    // }
    // if (keyNode == NULL)
    // {
    //     return; // Key not found
    // }

    // if (keyNode->left != NULL)
    // {
    //     node *lefttree = keyNode->left;
    //     while (lefttree != NULL)
    //     {
    //         pre = lefttree;
    //         lefttree = lefttree->right;
    //     }
    // }

    // if (keyNode->right != NULL)
    // {
    //     node *righttree = keyNode->right;
    //     while (righttree != NULL)
    //     {
    //         suc = righttree;
    //         righttree = righttree->left;
    //     }
    // }
}


/*    
    Node* keyNode = root;
    if (keyNode == NULL)
    {
        pre = NULL;
        suc = NULL;
        return;
    }

    while (keyNode != NULL)
    {
        if (keyNode->key == key)
        {
            break;
        }
        if (keyNode->key > key)
        {
            suc = keyNode;
            keyNode = keyNode->left;
        }

        else
        {
            pre = keyNode;
            keyNode = keyNode->right;
        }
    }
    if (keyNode == NULL)
    {
        return; // Key not found
    }

    if (keyNode->left != NULL)
    {
        Node *lefttree = keyNode->left;
        while (lefttree != NULL)
        {
            pre = lefttree;
            lefttree = lefttree->right;
        }
    }

    if (keyNode->right != NULL)
    {
        Node *righttree = keyNode->right;
        while (righttree != NULL)
        {
            suc = righttree;
            righttree = righttree->left;
        }
    }*/
int main()
{
    node *root = new node(8);
    root->left = new node(1);
    root->right = new node(9);

    // root->left->left = new node(4);
    root->left->right = new node(4);
    root->left->right->left = new node(3);
    // root->right->left = new node(6);
    // root->right->right = new node(7);

    findPreSuc(root, 8);

    return 0;
}
