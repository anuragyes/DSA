#include <iostream>
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

int main()
{
    node *root = new node(2);
    node *left = new node(10);
    node *right = new node(10);
    return 0;
}