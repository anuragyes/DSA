/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
long Solution::coveredNodes(TreeNode* root) {
    long long uncovered = 0;
long long covered = 0;
queue<TreeNode*> q;
q.push(root);
while(!q.empty()){
int sz = q.size();
for(int i = 0 ; i < sz ; i++){
auto front = q.front();
q.pop();
if(i == 0 || i == sz -1){
uncovered += front->val;
}
else{
covered += front->val;
}
if(front->left){
q.push(front->left);
}
if(front->right){
q.push(front->right);
}
}
}
return abs(uncovered - covered);
}


You are given the root of a binary tree A, you need to return the absolute difference between sum of all covered elements and the sum of all uncovered elements.

In a binary tree, a node is called Uncovered if it appears either on left boundary or right boundary. Rest of the nodes are called covered.