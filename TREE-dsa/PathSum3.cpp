   optimal code using hasmap or unordered_map
class Solution {
public:
    unordered_map<long long, int> prefixSumCount;
    int count = 0;

    void dfs(TreeNode* node, long long currSum, int targetSum) {
        if (!node) return;

        currSum += node->val;

        // Check if there is a prefix sum that makes a valid path
        if (prefixSumCount.count(currSum - targetSum)) {
            count += prefixSumCount[currSum - targetSum];
        }

        // Update current prefix sum count
        prefixSumCount[currSum]++;

        // Recurse left and right
        dfs(node->left, currSum, targetSum);
        dfs(node->right, currSum, targetSum);

        // Backtrack: remove current prefix sum count after recursion
        prefixSumCount[currSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        prefixSumCount[0] = 1; // base case: empty path sum
        count = 0;
        dfs(root, 0, targetSum);
        return count;
    }
};


//  brute force approach

//  using recusion only 

 class Solution {
public:
    int count = 0;

    // Count paths starting from this node
    void countPaths(TreeNode* node, long long currentSum, int targetSum) {
        if (!node) return;

        currentSum += node->val;
        if (currentSum == targetSum) {
            count++;
        }

        countPaths(node->left, currentSum, targetSum);
        countPaths(node->right, currentSum, targetSum);
    }

    // Try every node as a starting point
    void dfs(TreeNode* node, int targetSum) {
        if (!node) return;

        countPaths(node, 0, targetSum);

        dfs(node->left, targetSum);
        dfs(node->right, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        count = 0;
        dfs(root, targetSum);
        return count;
    }
};
