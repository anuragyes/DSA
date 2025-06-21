#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// int main() {
//     int a[] = {10, 4, 2, 4, 1};
//     int n = 5;

//     stack<int> st;
//     vector<int> ans;
//     for (int i = n - 1; i >= 0; i--) {
//         while (!st.empty() && st.top() <= a[i]) {
//             st.pop();
//         }
//         if (st.empty()) {
//             ans.push_back(-1); // If no greater element to the right
//         } else {
//             ans.push_back(st.top());
//         }
//         st.push(a[i]);
//     }

//     // Reverse the vector to maintain original order
//     reverse(ans.begin(), ans.end());

//     for (int i = 0; i < ans.size(); i++) {
//         cout << ans[i] << endl;
//     }

//     return 0;
// }

int main()
{
    int a[] = {16, 17, 4, 3, 5, 2};
    int n = 6;

    stack<int> st;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {

        //  case first 
        if (st.empty())
        
            st.push(a[i]);
        //   case second 
        else if (!st.empty() && st.top() <= a[i])
        {
            ans.push_back(st.top());
            st.pop();
            st.push(a[i]);
        }
        //  case third 
        else
        
            continue;
        
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
};
