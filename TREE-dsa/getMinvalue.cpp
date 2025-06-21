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

node *getMin(node *root)
{
    // we all know that  in bst property say the last left node alway be min value in bst
    node *ptr = root;
    while (ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr;
}
node *getMax(node *root)
{
    // we all know that  in bst property say the last left node alway be  max value in bst
    node *ptr = root;
    while (ptr->right != NULL)
    {
        ptr = ptr->right;
    }
    return ptr;
}

/*
 int getMin(node *root)
 {



    //  approch first

    vector<int> ans = {12, 34, 56, 32, 31, 4};
    stack<int> st;
    for (int i = 0; i < ans.size(); i++)
    {
        if (st.empty())
        {
            st.push(ans[i]);
        }

        if (!st.empty())
        {
            if (st.top() > ans[i])
            {
                st.push(ans[i]);
            }
            else
            {
                st.push(st.top());
            }
        }
    }
    int answer = st.top();
    return answer;
    */
// }
int main()
{

    node *root = new node(100);
    root->left = new node(20);
    root->right = new node(200);
    root->left->left = new node(10);
    root->left->right = new node(30);
    root->right->left = new node(150);
    cout << " the min value in bst is : " << getMin(root)->data << endl;
    cout << " the max value in bst is : " << getMax(root)->data << endl;

    
    return 0;
}
