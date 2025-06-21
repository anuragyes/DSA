#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
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
    bool check(node* a, node* b) {
        //   edage cases 
        if (a == NULL && b == NULL) {
            return true;
        }
        if (a == NULL || b == NULL) {
            return false;
        }
        return (a->data == b->data) && check(a->left, b->left) &&
               check(a->right, b->right);
    }

    bool isSubtree(node* root, node* subRoot) {

        if (root == NULL) {
            return false;
        }
        return check(root, subRoot) || isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }


int main()
{
    node *root1 = new node(3);
    root1->left = new node(4);
    root1->right = new node(5);

    root1->left->left = new node(1);
    root1->left->right = new node(2);

    //  subtree
    node *root2 = new node(4);
    root2->left = new node(1);
    root2->right = new node(2);
    cout << isSubtree(root1, root2);

    return 0;
}
