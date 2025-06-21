#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// we have given array and if our array contains zeroes then these zeroes move at last

int main()
{
    int arr[10] = {1, 0, 3, 9, 0, 5, 0, 0, 3, 0};
    // int i = 0;
    // for (int j = 0; j < 10; j++)
    // {
    //     if (arr[j] != 0)
    //     {
    //         swap(arr[j], arr[i]);
    //         i++;
    //     }
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << arr[i] << endl;
    // }
    /*
    vector<int> ans;
    vector<int> zero;
    stack<int> st;

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] != 0)
        {
            st.push(arr[i]);
        }
        else
        {
            zero.push_back(arr[i]);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    int n = zero.size();
    int i = 0;
    while (n)
    {
        ans.push_back(zero[i]);

        i++;
        n--;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    */

    vector<int> ans;
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] != 0)
        {
            ans.push_back(arr[i]);
        }
        else
        {
            count++;
        }
    }

    while (count--)
    {
        ans.push_back(0);
    }
    for (int i = 0; i < 10; i++)
    {
        cout << ans[i] << endl;
    }
}