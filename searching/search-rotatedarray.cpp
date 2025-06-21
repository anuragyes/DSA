#include <iostream>
#include <vector>
using namespace std;

//  search  an element in sorted rotated array
int insertAtrightposition(vector<int> &arr, int k)
{

    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == k)
            return mid;

        //  check left side is sorted or not
        if (arr[start] <= arr[mid])
        {
            if (arr[start] <= k && k <= arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        //  check left side is sorted or not
        else if (arr[mid] <= k && k <= arr[end])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

int main()
{

    // vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    vector<int> arr = {12, 15, 18, 2, 4};
    cout << insertAtrightposition(arr, 2);
}