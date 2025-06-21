

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to calculate the span of stockâ€™s price for all n days.
vector<int> calculateSpan(int price[], int n)
{

    stack<int> st;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && price[i] > price[st.top()])
        {
            ans[st.top()] = st.top() - i;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        ans[st.top()] = st.top() + 1;
        st.pop();
    }
  for (int i = 0; i < ans.size(); i++)
  {
    cout<<ans[i]<<endl;
  }
  
}
int main()
{
    int arr[7] = {100, 80, 60, 70, 60, 75, 85};
    calculateSpan(arr,7);
    return 0;
}
