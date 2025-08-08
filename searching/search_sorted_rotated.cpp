#include <iostream>
using namespace std;

bool searchSortedArray(vector<int> &ans, int target)
{

    int start = 0;
    int end = arr.size() - 1;
    ;

    while (start < end)
    {

        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
            return true;

        //    check the left and right which one is sorted
        //   left part is sorted
        if (arr[start] < arr[mid])
        {

            if (arr[start] <= target && target < arr[mid])
            {
               end = mid - 1;
            }
            else
            {
                
                 start = mid + 1;
            }
        }
        else
        {
            // right part is sorted
            if (arr[mid] < target && target <= arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

      return -1;       //taerget not found 
}
