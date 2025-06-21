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
 
      vector<int> arr ={2, 2 , 3 , 3 , 3 , 3 , 4};
      cout << insertAtrightposition(arr, 3);

    
}