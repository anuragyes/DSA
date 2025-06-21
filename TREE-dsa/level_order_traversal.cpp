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

//   LOVE BABBAR
void levelorder(node *root)
{

    vector<int> result;
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++)
        {
            node *ptr = q.front();
            q.pop();
            result.push_back(ptr->data);

            if (ptr->left)
                q.push(ptr->left);
            if (ptr->right)
                q.push(ptr->right);
        }
    }
    for (int i = 0; i < result.size(); i++)
    {
        /* code */ cout << result[i] << endl;
    }
}

//  explain by shraddha didi

// void levelorder(node *root)
// {
//     if (root == NULL)
//         return;

//     queue<node *> q;

//     q.push(root);
//     q.push(NULL);

//     while (!q.empty())
//     {
//         node *ptr = q.front();
//         q.pop();
//         if (ptr != NULL)
//         {

//             cout << ptr->data << " ";
//             if (ptr->left)

//                 q.push(ptr->left);

//             if (ptr->right)

//                 q.push(ptr->right);

//             else if (!q.empty())

//                 q.push(NULL);
//         }
//     }
// }

int main()
{
    // node *root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);

    // root->left->left = new node(4);
    // root->left->right = new node(5);

    // root->right->left = new node(6);
    // root->right->right = new node(7);

    node *root = new node(3);
    root->left = new node(9);
    root->right = new node(20);

    root->right->left = new node(15);
    root->right->right = new node(7);
    // levelorder(root);
    cout << 0 % 2 << endl;

    return 0;
}
