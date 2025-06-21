// if array contains duplicate array return true otherwise false
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    int orignalSize = arr.size();
    set<int> st;
    for (int i = 0; i < orignalSize; i++)
    {
        st.insert(arr[i]);
    }
    int setSize = st.size();
    if (setSize == orignalSize)
        cout<<"true";
    else
        cout<<"false";    

    return 0;
}