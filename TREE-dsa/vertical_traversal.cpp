// /**
//  * Definition for binary tree
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
 
 
//   vector<vector<int>> Solution::verticalOrderTraversal(TreeNode* root) {
//     vector<vector<int>> ans;
//     if (!root) return ans;

//     // map<vertical_position, vector_of_nodes>
//     map<int, vector<int>> mp;
//     queue<pair<TreeNode*, int>> q;

//     q.push({root, 0});

//     while (!q.empty()) {
//         auto [node, pos] = q.front();
//         q.pop();

//         mp[pos].push_back(node->val);

//         if (node->left) q.push({node->left, pos - 1});
//         if (node->right) q.push({node->right, pos + 1});
//     }

//     // Collect result from leftmost to rightmost
//     for (auto &p : mp) {
//         ans.push_back(p.second);
//     }

//     return ans;
// }

/*
void find(TreeNode* root , int position , int &left , int &right){
    if(root == NULL) return;

    left = min(position, left);
    right = max(position, right);

    find(root->left, position - 1, left, right);
    find(root->right, position + 1, left, right);
}

vector<vector<int>> Solution::verticalOrderTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    int left = 0, right = 0;
    find(root, 0, left, right);

    vector<vector<int>> positive(right + 1);      // for pos >= 0
    vector<vector<int>> negative(abs(left) + 1);  // for pos < 0

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        int pos = q.front().second;
        TreeNode* node = q.front().first;
        q.pop();

        if (pos >= 0) {
            positive[pos].push_back(node->val);
        } else {
            negative[-pos].push_back(node->val);  // use -pos as index
        }

        if (node->left) q.push({node->left, pos - 1});
        if (node->right) q.push({node->right, pos + 1});
    }

    // Collect results from negative (left side) → right side
    for (int i = negative.size() - 1; i > 0; --i) {
        ans.push_back(negative[i]);
    }

    for (int i = 0; i < positive.size(); ++i) {
        ans.push_back(positive[i]);
    }

    return ans;
}

*/

  void find(TreeNode* root, int position , int &left , int &right){
      
         if(root==NULL)  return ;
         
          left = min(left,position);
          right = max(right,position);
          
          
            find(root->left , position-1,  left , right );
            find(root->right, position+1 , left , right);
  }
vector<vector<int>> Solution::verticalOrderTraversal(TreeNode* root) {
    vector<vector<int>>ans ;
    
     if(root==NULL)  return ans;
    // find the posyion 
      int left = 0;
       int right = 0;
       
        find(root,0,left, right );
        
        vector<vector<int>>postive(right+1);
        vector<vector<int>>negative(abs(left)+1);
        
         queue<pair<TreeNode*,int>>q;
          q.push({root,0});
         
           while(!q.empty()){
                TreeNode* node = q.front().first;
                int pos = q.front().second;
                q.pop();
                //   go to [postibe side ]
                  if(pos>=0){
                      postive[pos].push_back(node->val); 
                  }else{
                      negative[-pos].push_back(node->val);
                  }
                  
                  
                   if(node->left ){
                        q.push({node->left,pos-1});
                   }
                   
                    if(node->right ){
                        q.push({node->right,pos+1});
                   }
                    
           }
           
           
            for(int i=negative.size()-1 ; i>0 ; i--){
                ans.push_back(negative[i]);
            }
            
             for(int i=0;i<postive.size();i++){
                  ans.push_back(postive[i]);
             }
         
        
        
          return ans;
    
}

