

/*
For example:
Input: 'a' = [7, 12, 1, 20]

Output: NGE = [12, 20, 20, -1]

Explanation: For the given array,

- The next greater element for 7 is 12.

- The next greater element for 12 is 20.

- The next greater element for 1 is 20.

- There is no greater element for 20 on the right side. So we consider NGE as -1.*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*

int NextGreaterElement(int arr[], int size)
{

    vector<int> ans(size, -1);
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] <= arr[j])
            {
                ans[i] = arr[j];
                 break;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << endl;
    }
}
*/

// int main()
// {
//     int arr[] = {8, 6, 4, 7, 4, 9, 10, 8, 12};
//     int size = 9;

//     int ans = NextGreaterElement(arr, size);

//     return 0;
// }

//  this code for circular array
// class Solution
// {
// public:
//     vector<int> nextGreaterElements(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<int> nge(n, -1);
//         stack<int> st;
//         // for (int i = 2 * n - 1; i >= 0; i--)
//         for (int i = n - 1; i > 0; i--)
//         {
//             while (!st.empty() && st.top() <= nums[i % n])
//             {
//                 st.pop();
//             }

//             if (i < n)
//             {
//                 if (!st.empty())
//                     nge[i] = st.top();
//             }
//             st.push(nums[i % n]);
//         }
//         return nge;
//     }
// };

//  optimal approch
//  make three condition

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            vector<int> ans(n, -1);
            stack<int> st;
            for (int i = n - 1; i >= 0; i--)
            {
                while (!st.empty() && st.top() <= arr[i])
                {
                    st.pop();
                }
                if (!st.empty())
                {
                    ans[i] = st.top();
                }
                st.push(arr[i]);
            }
            return ans;
        }
    }
};
int main()
{
    Solution obj;
    vector<int> v{1, 2, 3, 4, 6, 3};
    vector<int> res = obj.nextGreaterElements(v);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}
