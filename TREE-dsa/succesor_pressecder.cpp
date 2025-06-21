#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

//  there are two ways to find out the given tree is bst ?
//   first approch inorder traverse ans check outcome ans  ansd make a variable count and when the value of counter equal to K just return
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

pair<int, int> predecssorSuccessor(node *root, int key)
{

    //  find key
    int pre = -1;
    int succ = -1;

    node *ptr = root;
    while (ptr->data != key)
    {
        if (ptr->data > key)
        {
            succ = ptr->data;
            ptr = ptr->left;
        }
        else
        {
            pre = ptr->data;
            ptr = ptr->right;
        }
    }

    // find pre and succ

    node *lefttree = ptr->left;
    while (lefttree != NULL)
    {
        pre = lefttree->data;
        lefttree = lefttree->right;
    }

    node *righttree = ptr->left;
    while (righttree != NULL)
    {
        succ = righttree->data;
        righttree = righttree->left;
    }
    pair<int, int> ans = make_pair(pre, succ); 
    return ans;
}

int main()
{
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(5);

    root->left->left = new node(1);
    root->left->right = new node(3);
    predecssorSuccessor(root, 3);

    return 0;
}
