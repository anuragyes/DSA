/*class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
         vector<int>ans;
    //  base case 
     if(root==NULL) return ans;
     
     queue<Node*>q;
     q.push(root);
     while(!q.empty())
    {
         int n = q.size();
         
       ans.push_back(q.front()->data);
          while(n--)
         {
           Node* node = q.front();
           q.pop();
           if(node->right)
              q.push(node->right);
              
          
           if(node->left)
                q.push(node->left);
         } 
    }
         
           return ans;
     
    }
};*/