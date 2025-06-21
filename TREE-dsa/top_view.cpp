

//  learn by coder army
/*


class Solution
{
   public:
   //Function to return a list of nodes visible from the top view
   //from left to right in Binary Tree.
 void  find(Node* root , int pos , int &leftmost , int &rightmost){
       if(root==NULL) return ;

       leftmost = min(leftmost,pos);
       rightmost = max(rightmost,pos);
       find(root->left,pos-1,leftmost,rightmost);
        find(root->right,pos+1,leftmost,rightmost);

   }
   vector<int> topView(Node *root)
   {
        int leftmost = 0 ;
        int rightmost = 0;
//   step first find the space of elements which is store the answer 
        find(root,0,leftmost,rightmost);

// space where the  elements  will be  stored 
         vector<int>ans(rightmost-leftmost+1);
         vector<bool>visited(rightmost-leftmost+1,0);

          queue<Node*>q;
          queue<int>index;


           q.push(root);
           index.push(-1*leftmost);

           while(!q.empty()){
               Node* node = q.front();
               q.pop();

               int pos = index.front();
               index.pop();

                if(!visited[pos]){
                    visited[pos]=1;
                    ans[pos]=node->data;
                }

               if(node->left){
                   q.push(node->left);
                   index.push(pos-1);
               }

               if(node->right){
                   q.push(node->right);
                    index.push(pos+1);
               }


           }
            return ans;
   }

};
*/

#include <iostream>
#include <vector>
#include <map>
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

vector<int> top_view(node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;
    queue<pair<node *, int>> q;
    map<int, int> mapp;

    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        node *ptr = it.first;
        int line = it.second;
        if (mapp.find(line) == mapp.end())
        {
            mapp[line] = ptr->data;
        }
        if (ptr->left)
        {
            q.push({root->left, line - 1});
        }
        if (ptr->right)
        {
            q.push({root->left, line + 1});
        }
    }
    for (auto it : mapp)
    {
        cout << ans[it.second] << endl;
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    // root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);
    top_view(root);

    return 0;
}
