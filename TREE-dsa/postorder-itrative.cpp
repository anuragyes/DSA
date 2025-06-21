/*class Solution{
    public:
    vector<int> postOrder(Node* root) {
      vector<int>ans;
       stack<Node*>st;
        if(root==NULL) return ans;
        
         st.push(root);
         while(!st.empty()){
              Node* front = st.top();
               ans.push_back(st.top()->data);
               st.pop();
               
                if(front->left){
                    st.push(front->left);
                }
                
                  if(front->right){
                    st.push(front->right);
                }
         }
         
         reverse(ans.begin(),ans.end());
          return ans;
    }
};*/