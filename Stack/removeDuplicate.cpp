#include <iostream>
#include <stack>
#include <unordered_set>
using namespace std;

//  find duplicate element is present is return true else return false;

bool removeDuplicates(stack<int> &mystack, unordered_set<int> seen)
{
    if (mystack.empty())
    {
        return false;
    }

    int num = mystack.top();
    mystack.pop();
    if (seen.find(num) != seen.end())
    {
        return true;
    }
    seen.insert(num);
    bool check = removeDuplicates(mystack, seen);
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

    unordered_set<int> seen;

    if (removeDuplicates(myStack, seen))
    {
        cout << "Duplicate present " << endl;
    }
    else
    {
        cout << "Duplicate is not present" << endl;
    }
    // cout << minValue << endl;
}