
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
    myStack.push(3);
    myStack.push(5);
    myStack.push(4);

    unordered_set<int> seen;