#include <iostream>
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

bool isIsomorphic(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->data != root2->data)
    {
        return false;
    }
     
return ( isIsomorphic(root1->left,root2->left)&&  isIsomorphic(root1->right,root2->right))||
 ( isIsomorphic(root1->left,root2->right) &&  isIsomorphic(root1->right,root2->left));
     
     
}

int main()
{
    node *root1 = new node(3);
    root1->right = new node(20);

    root1->right->left = new node(56);
    root1->right->right = new node(7);

    node *root2 = new node(3);
    root2->right = new node(20);

    root2->right->left = new node(7);
    root2->right->right = new node(56);

    cout << isIsomorphic(root1, root2);

    return 0;
}
