#include <iostream>
#include <vector>
using namespace std;

//  approch to acchive  bounday traversal
/*
 1) print all left nodes don't print leaves node ;
 2) print all  leaves nodes;
 3) print all right nodes but in reverse  way
*/

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

void lefttraversal(node *root, vector<int> &ans)
{ // base case
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    ans.push_back(root->data);

    if (root->left)
    {
        lefttraversal(root->left, ans);
    }
    else
    {
        lefttraversal(root->right, ans);
    }
}

void leaftraversal(node *root, vector<int> &ans)
{
    //  base case
    if (root == NULL)
        return;
    //  if you are leaf node , store into ans
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    leaftraversal(root->left, ans);
    leaftraversal(root->right, ans);
}
void righttraversal(node *root, vector<int> &ans)
{

    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;

    if (root->right)
    {
        righttraversal(root->right, ans);
    }
    else
    {
        righttraversal(root->left, ans);
    }

    //  back to the root node after visiting both node right and left
    ans.push_back(root->data);
}
vector<int> boundry_traversal(node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    //  left traversal
    lefttraversal(root->left, ans);
    //  leaf print
    //  in left side
    leaftraversal(root->left, ans);
    //  in right side
    leaftraversal(root->right, ans);
    //   right traversal
    righttraversal(root->right, ans);

    int sum = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        sum += ans[i];
    }

    return ans;
    // return sum;
}

int findSum(vector<int> &ans)
{
    int sum = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        sum += ans[i];
    }

    return sum;
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

    boundry_traversal(root);

   
    return 0;
}
