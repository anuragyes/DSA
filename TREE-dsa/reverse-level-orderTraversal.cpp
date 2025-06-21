/*

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> vec;
   queue<Node*>q;
   if(!root)
   return vec;
   q.push(root);
   while(!q.empty()){
       Node* temp= q.front();
       q.pop();
       vec.push_back(temp->data);
       if(temp->right){
           q.push(temp->right);

       }
       if(temp->left){
           q.push(temp->left);
       }
   }

   reverse(vec.begin(), vec.end());
   return vec;
}


*/