#include <iostream>
using namespace std;

vector<int> reverseLevelOrder(Node *root)
{

    vector<int> a;
    if (root == NULL)
    {
        return a;
    }
    stack<int> s;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *t = q.front();
        q.pop();
        s.push(t->data);
        if (t->right)
        {
            q.push(t->right);
        }
        if (t->left)
        {
            q.push(t->left);
        }
    }
    while (!s.empty())
    {
        a.push_back(s.top());
        s.pop();
    }
    return a;
}