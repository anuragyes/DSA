
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    string ans = "(2*(a+b))";

    stack<int> st;
    for (int i = 0; i < ans.size(); i++)
    {
        char ch = ans[i];

        if (ch == '(' || ch == '*' || ch == '+' || ch == '-' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isredundant = true;
                while (st.top() != '(')
                {
                    char peek = st.top();
                    if (peek == '(' || peek == '*' || peek == '+' || peek == '-' || peek == '/')
                    {
                        isredundant = false;
                    }
                    st.pop();
                }
                if (isredundant == true)
                    return true;
                st.pop();
            }
        }
    }
    return false;
}