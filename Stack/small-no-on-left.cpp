#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> leftSmaller(int n, int a[])
    {
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && a[st.top()] >= a[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(a[st.top()]);
            }
            st.push(i);
        }
        return ans;
    }
};