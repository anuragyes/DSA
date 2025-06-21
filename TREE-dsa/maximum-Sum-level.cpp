/*
class Solution{
  public:
    // You are required to complete below method 
    int maxLevelSum(Node* root) {
        int maxSum = INT_MIN;
        if (!root) return 0;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int  levelSum = 0;

            for (int i = 0; i < levelSize; ++i) {
                Node* node = q.front();
                q.pop();
                levelSum += node->data;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

             maxSum = max(maxSum,levelSum);
        }

        return maxSum;
    }
};

*/