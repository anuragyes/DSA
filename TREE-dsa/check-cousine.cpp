/* if (root == nullptr) return false;

    queue<Node*> q;
    q.push(root);
    int levelA = -1, levelB = -1;
    int level = 0;

    while (!q.empty()) {
        int n = q.size();
        levelA = levelB = -1; // Reset levels for this level

        while (n--) {
            Node* temp = q.front();
            q.pop();

            if (temp->data == a) levelA = level;
            if (temp->data == b) levelB = level;

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        // If both nodes are found at this level, check if they are siblings
        if (levelA != -1 && levelB != -1) {
            return levelA == levelB && !areSiblings(root, a, b);
        }

        level++;
    }

    return false;*/