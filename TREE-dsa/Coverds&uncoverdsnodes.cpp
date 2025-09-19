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
queue<TreeNode*> q ;
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



Problem Constraints
1 <= Number of nodes in the binary tree <= 105


Input Format
The first argument is the root of the binary tree A.


Output Format
Return a single integer denoting the absolute difference of the sum of covered and uncovered nodes.


Example Input
Input 1:
    2
   / \
  1   4
 /   / \
6  10   5
Input 2:

      1
     /
    2
   /
  3


Example Output
Output 1:
8
Output 2:

6


Example Explanation
Explanation 1:
The node with value 10 is the only covered node. All other nodes are uncovered.
Therefore, the absolute difference is |(10) - (2 + 1 + 4 + 6 + 5)| = 8
Explanation 2:

All the given nodes are uncovered. Hence, the answer is sum of given nodes - 6.

