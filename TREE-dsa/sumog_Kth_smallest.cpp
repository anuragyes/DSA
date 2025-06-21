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

void inorder(node *root, int k, vector<int> &ans)
{
    if (root == NULL)
        return;
    inorder(root->left, k, ans);
    ans.push_back(root->data);
    inorder(root->right, k, ans);
}

int sum(node *root, int k)
{
    vector<int> ans;
    inorder(root, k, ans);
    int sumel = 0;

    for (int i = 0; i < k; i++)
    {
        sumel = sumel + ans[i];
    }
    return sumel;
}

int main()
{

    node *root = new node(100);
    root->left = new node(20);
    root->right = new node(200);
    root->left->left = new node(10);
    root->left->right = new node(30);
    root->right->left = new node(150);
    // cout << sum(root, 2) << endl;
    int k = 3;
    vector<int> s = {12, 45, 67, 89, 9, 87, 65};
    float index = s.size() / 2;
    cout << s[index];
    return 0;
}
