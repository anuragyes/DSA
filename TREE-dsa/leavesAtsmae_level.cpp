#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {

        data = val;
        left = NULL;
        right = NULL;
    }
};
int ans = 1;
void solve(node *root1, int h, int &ma)
{
    if (!root1)
    {
        return;
    }
    if (ans == 0)
        return;
    if (!root1->left && !root1->right)
    {
        if (ma == -1)
        {
            ma = h;
        }
        else
        {
            if (h != ma)
            {
                ans = 0;
            }
        }
        return;
    }
    solve(root1->left, h + 1, ma);
    solve(root1->right, h + 1, ma);
}

bool check(node *root1)
{
    int ma = -1;
    int h = 0;
    ans = 1;
    solve(root1, h, ma);
    return ans;
}

int main()
{
    node *root1 = new node(3);
    root1->left = new node(4);
    root1->right = new node(5);

    // root1->left->left = new node(1);
    // root1->left->right = new node(2);
    cout << check(root1);

    return 0;
}
