#include <iostream>
#include <vector>
#include <queue>
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

int sumofK(node *root, int k)
{
    int count = 0;
    int sum = 0;
    if (root == NULL)
        return -1;

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp != NULL)
        {
            if (count == k)
            {
                sum = sum + temp->data;
            }
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            count++;
        }
    }
    return sum;
    cout << "ans";
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
   
   cout<<1%4;
//    cout<<  sumofK(root,2);
    return 0;
}