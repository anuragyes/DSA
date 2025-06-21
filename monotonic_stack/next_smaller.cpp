#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
// public:
//     vector<int> nextGreaterElements(vector<int> &arr)
//     {
//         int n = arr.size();
//         vector<int> ans(n, -1);
//         stack<int> st;
//         for (int i = 0; i < n-1 ; i++)
//         {
//             while (!st.empty() && st.top() >= arr[i])
//             {
//                 st.pop();
//             }
//             if (st.empty() == false)
//                 ans[i] = st.top();
//             st.push(arr[i]);
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {

            while (!st.empty() && arr[st.top()] > arr[i])
            {

                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> v{7, 12, 1, 20};
    vector<int> res = obj.nextGreaterElements(v);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}
