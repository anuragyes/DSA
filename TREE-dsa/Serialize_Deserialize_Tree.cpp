

 #include <iostream>
 #include <queue>
 #include <string>
 using namespace  std;
//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "null";
        }

        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                ss << node->val << ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                ss << "null,";
            }
        }
        
        string result = ss.str();
        result.pop_back(); // Remove the trailing comma
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null") {
            return NULL;
        }

        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (getline(ss, val, ',')) {
            TreeNode* current = q.front();
            q.pop();

            if (val != "null") {
                current->left = new TreeNode(stoi(val));
                q.push(current->left);
            }

            if (getline(ss, val, ',')) {
                if (val != "null") {
                    current->right = new TreeNode(stoi(val));
                    q.push(current->right);
                }
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));