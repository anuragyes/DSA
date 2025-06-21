#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {12, 34, 3, 22};
    int size = 4;

    stack<int> st;
    for (int i = 0; i < size; i++)
    {
        // st.push(arr[i]);

        arr[st.top()] ;
        
    }
     cout<<st.top()<<endl;
}