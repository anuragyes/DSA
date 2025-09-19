#include <bits/stdc++.h>

bool duplicateParanthesis(string &expr)
{
   

    stack<char> st;
    for (auto element : expr)
    {

        if (element == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                return true;
            }

            while (!st.empty() && st.top() != '(')
            {
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }
        else
        {
            st.push(element);
        }
    }
    return false;
};