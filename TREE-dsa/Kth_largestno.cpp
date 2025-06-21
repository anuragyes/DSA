/*class Solution
{
    public:
    
    
    int kthLargest(Node *root, int k)
    {
       
       stack<Node*> nodes;
        Node* curr = root;
        int count = 0;

        while (curr != nullptr || !nodes.empty()) {
            while (curr != nullptr) {
                nodes.push(curr);
                curr = curr->right; // Traverse right first for reverse in-order
            }
            curr = nodes.top();
            nodes.pop();
            count++;
            if (count == k)
                return curr->data;
            curr = curr->left;
        }
        return -1; // Invalid k or empty tree
         
    }
};

*/