/*class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        stack<Node*>st;
        stack<bool>visited;
        vector<int>ans;
         
         st.push(root);
         visited.push(0);
         
          while(!st.empty()){
              Node* front = st.top();
              st.pop();
              bool flag = visited.top();
              visited.pop();
              
              if(!flag)
              {
                  if(front->right){
                      st.push(front->right);
                      visited.push(0);
                      
                  }
                   st.push(front);
                   visited.push(1);
                   
                   if(front->left){
                        st.push(front->left);
                        visited.push(0);
                   }
                    
              }else{
                  ans.push_back(front->data);
              }
          }
           return ans;
    }
};
*/