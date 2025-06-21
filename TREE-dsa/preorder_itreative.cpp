#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//  find max height

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

vector<int> preorder_itrative(node *root)
{
    vector<int> preorder;

    if (root == NULL)
    {
        return preorder;
    }
    stack<node *> st;
    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if (root->right != NULL)
        {
            st.push(root->right);
        }
        if (root->left != NULL)
        {
            st.push(root->left);
        }
    }
    return preorder;
}

int height(node *root)
{
    if (root == NULL)

        return 0;

    int leftside = height(root->left);

    int rightside = height(root->right);

    return 1 + max(leftside, rightside);
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);
    // cout << "the maximum height of the given tree is " << height(root);
    // cout << endl;
    vector<int> preorder;
    preorder = preorder_itrative(root);

    cout << "The preOrder Traversal is : ";
    for (int i = 0; i < preorder.size(); i++)
    {
        cout << preorder[i] << " ";
    }

    return 0;
}
