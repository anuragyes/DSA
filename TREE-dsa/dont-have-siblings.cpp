

/*Print all nodes that don't have sibling*/
/*Input :
       37
      /
    20
    /
  113

Output:
20 113
Explanation:
Nodes 20 and 113 dont have any siblings.*/

/*void solver(Node* node, vector<int> &ans) {
    if(!node) return;

    if(!(node->left) && node->right) {
        ans.push_back(node->right->data);
    }
    else if(!(node->right) && node->left){
        ans.push_back(node->left->data);
    }
        solver(node->left, ans);
        solver(node->right, ans);
}
vector<int> noSibling(Node* node)
{

      // code here
    vector<int> ans;
    solver(node, ans);
    if(ans.size()==0)
        ans.push_back(-1);
    else
        sort(ans.begin(), ans.end());
    return ans;


}*/