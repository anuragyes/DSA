#include <iostream>
#include <stack>
using namespace std;

void removeStars(string &str, string &ans, stack<char> &charStack, size_t index)
{
    if (index >= str.length())
    {
        while (!charStack.empty())
        {
            ans.push_back(charStack.top());
            charStack.pop();
        }
        return;
    }

    char ch = str[index];

    if (ch != '*')
    {
        charStack.push(ch);
    }

    removeStars(str, ans, charStack, index + 1);
}

int main()
{
    string str = "leet**c**ode*";
    string ans = "";
    stack<char> charStack;

    removeStars(str, ans, charStack, 0);

    cout << "Modified string: " << ans << endl;

    return 0;
}
