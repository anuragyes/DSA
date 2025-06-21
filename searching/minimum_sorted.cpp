#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//  find minimum   element in sorted rotated array
int insertAtrightposition(vector<int> &arr)
{

    int start = 0;
    int end = arr.size() - 1;
    int ans = INT16_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] >= arr[start])
        {
            ans = min(ans, arr[mid]);
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
            ans = min(ans, arr[mid]);
        }
    }
    return ans;
}
int main()
{

    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    // vector<int> arr = {12, 15, 18, 2, 4};
    cout << insertAtrightposition(arr);
}