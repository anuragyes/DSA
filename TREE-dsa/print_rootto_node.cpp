// #include <iostream>
// #include <vector>
// #include <queue>
// #include <math.h>
// using namespace std;

// class node
// {
// public:
//     int data;
//     node *left;
//     node *right;
//     node(int val)
//     {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// int lowestcommon(node *root, int node)
// {
//     vector<int> ans;
//     queue<node *> q;
//     if (root == NULL)
//     {
//         return;
//     }
//     ans.push_back(root->data);
//     if (ans.front() == node)
//     {
//          return;
//     }
//     int leftside = lowestcommon(root->left, node);
    
// }

// int main()
// {
//     node *root = new node(4);
//     root->left = new node(2);
//     root->right = new node(5);

//     root->left->left = new node(1);
//     root->left->right = new node(3);

//     return 0;
// }
