#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition of a binary tree node
struct Node
{
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void findDiagonal(Node *root, int position, vector<vector<int>> &ans)
{
    if (!root)
    {
        return;
    }

    // Ensure the vector has enough capacity to store the diagonal elements
    // if (ans.size() <= position)
    // {
    //     ans.resize(position + 1);
    // }

    ans[position].push_back(root->data);
    findDiagonal(root->left, position + 1, ans);
    findDiagonal(root->right, position, ans);
}

void find(Node *root, int pos, int &l)
{
    if (!root)
    {
        return;
    }

    l = max(pos, l);
    find(root->left, pos + 1, l);
    find(root->right, pos, l);
}

vector<int> diagonal(Node *root)
{
    if (!root)
    {
        return {}; // Return empty vector for empty tree
    }

    int left = 0;
    find(root, 0, left);

    vector<vector<int>> ans(left + 1);
    findDiagonal(root, 0, ans);

    vector<int> temp;

    // Flatten the diagonal vectors into a single vector
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            temp.push_back(ans[i][j]);
        }
    }

    return temp;
}

// Example usage
int main()
{
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    vector<int> result = diagonal(root);

    cout << "Diagonal traversal result:" << endl;
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
