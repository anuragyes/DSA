#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#include <iostream>
#include <climits>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* findGreatestLessThanOrEqual(TreeNode* root, int n) {
        TreeNode* closest = nullptr;
        while (root) {
            if (root->val <= n) {
                closest = root;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return closest;
    }
};

int main() {
   return 0;
}