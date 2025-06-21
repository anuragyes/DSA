#include <iostream>
#include <stack>
#include <unordered_set>
using namespace std;

//   find  the index  of given value  from top;

int Index(stack<int> &mystack, int value, int count = 0)
{

    //  base case
    if (mystack.empty())
    {
        return -1;
    }

    int num = mystack.top();
    mystack.pop();

    if (num == value)
    {
        return count;
    }

    int check = Index(mystack, value, count + 1);
    mystack.push(num);
    return check;
}

int main()
{
    stack<int> myStack;
    myStack.push(10);
    myStack.push(5);
    myStack.push(3);
    myStack.push(124);
    myStack.push(523);
    myStack.push(453);
    myStack.push(45);
    int value = 1924;
    int count = 0;

    int result = Index(myStack, value, count);
    if (result != -1)
    {
        std::cout << "Element " << value << " found at index " << result << endl;
    }
    else
    {
        std::cout << "Element " << value << " not found in the stack." << endl;
    }
}