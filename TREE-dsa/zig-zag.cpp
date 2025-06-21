/*vector<int> findSpiral(Node *root)
{
     stack<Node*>s1;   //right to left
     stack<Node*>s2;   // left to right

     s1.push(root);
      vector<int>ans;
      while(!s1.empty() || !s2.empty()){
           if(!s1.empty()){
               while(!s1.empty()){
                   Node* node = s1.top();
                   s1.pop();
                    ans.push_back(node->data);
                     if(node->right)
                     s2.push(node->right);

                      if(node->left)
                      s2.push(node->left);
               }
           }else{

                while(!s2.empty()){
                    Node* temp = s2.top();
                    s2.pop();
                    ans.push_back(temp->data);

                     if(temp->left)
                     s1.push(temp->left);


                     if(temp->right)
                     s1.push(temp->right);
                }
           }
      }
       return ans;
}*/