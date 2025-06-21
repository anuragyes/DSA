#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

//  brute force approch

void inorder(TreeNode *root, vector<int> &res)
{
    if (root == NULL)
        return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}

vector<int> findCommon(TreeNode *root1, TreeNode *root2)
{
    vector<int> first, second;
    inorder(root1, first);
    inorder(root2, second);

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    vector<int> common;
    int i = 0, j = 0;

    // Find common elements.
    while (i < first.size() && j < second.size())
    {
        if (first[i] == second[j])
        {
            common.push_back(first[i]);
            i++;
            j++;
        }
        else if (first[i] < second[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return common;
}

//   optimal approch

/*

vector<int> findCommon(TreeNode *root1, TreeNode *root2)
{
    stack<TreeNode *> st1, st2;
    vector<int> ans;

    while (root1)
    {
        st1.push(root1);
        root1 = root1->left;
    }

    while (root2)
    {
        st2.push(root2);
        root2 = root2->left;
    }

    while (!st1.empty() && !st2.empty())
    {
        TreeNode *top1 = st1.top();
        TreeNode *top2 = st2.top();

        if (top1->data == top2->data)
        {
            ans.push_back(top1->data);
            st1.pop();
            st2.pop();

            // Move to the right subtrees
            root1 = top1->right;
            root2 = top2->right;

            while (root1)
            {
                st1.push(root1);
                root1 = root1->left;
            }
            while (root2)
            {
                st2.push(root2);
                root2 = root2->left;
            }
        }
        else if (top1->data < top2->data)
        {
            st1.pop();
            root1 = top1->right;
            while (root1)
            {
                st1.push(root1);
                root1 = root1->left;
            }
        }
        else
        {
            st2.pop();
            root2 = top2->right;
            while (root2)
            {
                st2.push(root2);
                root2 = root2->left;
            }
        }
    }

    return ans;
}

*/
int main()
{
    // Create two BSTs
    TreeNode *root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);

    TreeNode *root2 = new TreeNode(5);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(7);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);

    // Find common elements between the two BSTs
    // vector<int> finally = findCommon(root1, root2);
    // for (int i = 0; i < finally.size(); i++)
    // {
    //     cout << finally[i] << " ";
    // }
    // cout << findCommon(root1, root2);

    return 0;
}
