

#include <iostream>
#include <stack>
using namespace std;

int findMax(stack<int> &mystack)
{
    int assume = mystack.top();
    mystack.pop();
    if (mystack.empty())
    {
        return assume;
    }
    int rest = findMax(mystack);
    return max(assume, rest);
}

int main()
{
    stack<int> myStack;

    myStack.push(3);
    myStack.push(45);
    myStack.push(24);
    myStack.push(40);

    int minValue = findMax(myStack);

    if (minValue != -1)
    {
        cout << "Minimum value in the stack: " << minValue << endl;
    }

    return 0;
}
