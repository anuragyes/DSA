


class Solution {
    public:
      // Helper function to return a pair of sums
      pair<int, int> solve(Node* root) {
          if (!root) return {0, 0};
          
          auto left = solve(root->left);
          auto right = solve(root->right);
          
          // If we include current node, we can't include its children
          int include = root->data + left.second + right.second;
          
          // If we exclude current node, we can take max of including or excluding children
          int exclude = max(left.first, left.second) + max(right.first, right.second);
          
          return {include, exclude};
      }
  
      int getMaxSum(Node* root) {
          auto res = solve(root);
          return max(res.first, res.second);
      }
  };
  