// vector<int> ans;
//     if (root == NULL) return ans;

//     queue<pair<TreeNode<int>*, int>> q;
//     map<int, int> maap;  // horizontal level -> node->data

//     q.push({root, 0});

//     while (!q.empty()) {
//         auto p = q.front();
//         q.pop();

//         TreeNode<int>* node = p.first;
//         int level = p.second;

//         // Always overwrite to get the bottom-most
//         maap[level] = node->data;

//         if (node->left) {
//             q.push({node->left, level - 1});
//         }
//         if (node->right) {
//             q.push({node->right, level + 1});
//         }
//     }

//     for (auto element : maap) {
//         ans.push_back(element.second);
//     }

//     return ans;