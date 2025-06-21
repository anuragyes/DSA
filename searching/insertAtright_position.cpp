#include <iostream>
#include <vector>
using namespace std;


//  insert at right position   an element 
int insertAtrightposition(vector<int> &arr, int element)
{

    int start = 0;
    int ans = arr.size();
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] >= element)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    // vector<int> arr = {1, 3, 5, 6};
      vector<int> arr ={1,3,5,6};
      cout << insertAtrightposition(arr, 5);

    // cout << insertAtrightposition(arr, 2);
}