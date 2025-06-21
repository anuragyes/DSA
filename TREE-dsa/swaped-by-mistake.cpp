/*class Solution {
public:

    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr;
        TreeNode* prev = nullptr;

        // In-order traversal using iterative method with stack
        stack<TreeNode*> stk;
        TreeNode* current = root;

        while (current != nullptr || !stk.empty()) {
            while (current != nullptr) {
                stk.push(current);
                current = current->left;
            }

            current = stk.top();
            stk.pop();

            // Compare current with previous node
            if (prev != nullptr && prev->val >= current->val) {
                if (first == nullptr) {
                    first = prev; // Found first incorrect node
                }
                second = current; // Update second incorrect node
            }

            prev = current;
            current = current->right;
        }

        // Swap the values of first and second incorrect nodes
        if (first != nullptr && second != nullptr) {
            swap(first->val, second->val);
        }
    }
};*/