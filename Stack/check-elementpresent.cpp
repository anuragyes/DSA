#include <iostream>
#include <stack>
#include <unordered_set>
using namespace std;

//   find given element is present  return true else return false;

bool removeDuplicates(stack<int> &mystack, int value)
{

    //  base case
    if (mystack.empty())
    {
        return false;
    }

    int num = mystack.top();
    mystack.pop();
    if (num == value)
    {
        return true;
    }

    bool check = removeDuplicates(mystack, value);
    mystack.push(num);

    return check;
}

int main()
{
    stack<int> myStack;
    // myStack.push(3);
    myStack.push(5);
    myStack.push(3);
    myStack.push(4);

    if (removeDuplicates(myStack, 10))
    {
        cout << "Element present " << endl;
    }
    else
    {
        cout << "Element is not present" << endl;
    }
}