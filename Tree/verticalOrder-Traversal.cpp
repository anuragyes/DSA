#include <iostream>
#include <queue>
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

void find(node *root, int position, int &left, int &right)
{
    if (!root)
        return;

    left = min(left, position);
    right = max(right, position);

    find(root->left, position - 1, left, right);
    find(root->right, position + 1, left, right);
}

vector<int> verticalOrder(node *root)
{
    vector<int> ans;
    if (!root)
        return ans; // Edge case: empty tree

    int left = 0, right = 0;
    find(root, 0, left, right);

    // Use arrays instead of vectors since we know the exact size
    vector<vector<int>> positive(right + 1);     // for positions >= 0
    vector<vector<int>> negative(abs(left) + 1); // for positions < 0

    queue<node *> q;
    queue<int> index;
    q.push(root);
    index.push(0);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();

        if (pos >= 0)
        {
            positive[pos].push_back(temp->data);
        }
        else
        {
            negative[abs(pos)].push_back(temp->data);
        }

        if (temp->left)
        {
            q.push(temp->left);
            index.push(pos - 1);
        }
        if (temp->right)
        {
            q.push(temp->right);
            index.push(pos + 1);
        }
    }

    // Collect results from negative positions in reverse order
    for (int i = negative.size() - 1; i > 0; --i)
    {
        for (int j = 0; j < negative[i].size(); ++j)
        {
            ans.push_back(negative[i][j]);
        }
    }

    // Collect results from positive positions
    for (int i = 0; i < positive.size(); ++i)
    {
        for (int j = 0; j < positive[i].size(); ++j)
        {
            ans.push_back(positive[i][j]);
        }
    }

    return ans;
}

int main()
{
    return 0;
}