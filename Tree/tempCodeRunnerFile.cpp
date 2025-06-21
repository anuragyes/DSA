bool same(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return false;
    if (root1 != NULL && root2 == NULL)
        return false;
    if (root1 == NULL && root2 != NULL)
        return false;

    bool left = same(root1->left, root2->left);
    bool right = same(root1->right, root2->right);
    bool diff = root1->data == root2->data;

    if (left && right && diff)
    {
        return true;
    }
    else
    {
        return false;
    }
}