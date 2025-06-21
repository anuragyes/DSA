
#include <iostream>
#include <stack>
#include <string>

bool isValidParentheses(const std::string &s)
{
    std::stack<char> stack;

    for (int i = 0; i < s.length(); i++) // firstly push all the element into stack
    {
        char ch = s[i];

        if (ch == '[' || ch == '(' || ch == '{') // if  we have open bracket than push into the stack,
        {
            stack.push(ch);
        }
        else
        {
            if (stack.empty()) // check stack is empty ? return false else
            {

                return false;
            }
            char top = stack.top(); // grab top element and pop  and check if top element is  not equal
                                    //   to  open bracket  return false
            stack.pop();

            if ((ch == '}' && top != '{') ||
                (ch == ')') && top != '(' ||
                (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return stack.empty(); // but at last check if our stack become empty its means valid ans
};

int main()
{
    std::string input;
    std::cout << "Enter parentheses string: ";
    std::cin >> input;

    if (isValidParentheses(input))
    {
        std::cout << "Valid parentheses!";
    }
    else
    {
        std::cout << "Invalid parentheses!";
    }

    return 0;
}
