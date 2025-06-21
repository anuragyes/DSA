#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int> &myStack, int middle, int count = 0)
{
    if (myStack.empty() || middle == count)
    {
        myStack.pop();
        return;
    }
    int num = myStack.top();
    myStack.pop();
    deleteMiddle(myStack, middle, count+1);
    myStack.push(num);
}
int main()
{
    stack<int> stk;
    cout << "befor the deleting element" << endl;
    for (int i = 1; i <= 5; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    // Push elements into the stack
    for (int i = 1; i <= 5; ++i)
    {
        stk.push(i);
    }

    // Get the middle index
    int middle = stk.size() / 2;

    // Delete the middle element
    deleteMiddle(stk, middle);

    // Print the remaining elements in the stack
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }

    return 0;
}
