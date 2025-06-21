/*#include <stack>
#include <vector>
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    vector<int> ans(n, -1); // Initialize ans with size n and default value -1
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];

        // Pop elements from the stack while they are greater than or equal to current element
        while (!st.empty() && st.top() >= curr) {
            st.pop();
        }

        // If stack is not empty, the top element is the next smaller element
        if (!st.empty()) {
            ans[i] = st.top();
        }

        // Push current element onto the stack
        st.push(curr);
    }

    return ans;
}*/