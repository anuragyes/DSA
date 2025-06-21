#include <iostream>
#include <vector>
using namespace std;
//  brute force approch  linear search

// int findSingleElement(int arr[], int size) {
//     int result = arr[0];

//     for (int i = 1; i < size; i++) {
//         result = result ^ arr[i];
//     }

//     return result;
// }

// int main() {
//     int arr[] = {1, 1, 2, 2, 3, 4, 4, 5, 5};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     int singleElement = findSingleElement(arr, size);

//     cout << "The element that appears only once is: " << singleElement << endl;

//     return 0;
// }

// binary serach optimal approch

int singleNonDuplicate(vector<int> &nums)
{

    int n = nums.size();
    int start = 1;
    int end = n - 2;
    // In  case when we have only one element 
    if (n == 1)
        return nums[0];
        // In case when we have two element but not same  return any one element 
    if (nums[0] != nums[1])
        return nums[0];

    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    while (start <= end)
    {
        int mid = (start + end) / 2;

//  when we have mid answer where mid-1 != mid+1 it means mid is the answer 
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
        {
            return nums[mid];
        }

        //  left half
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
            (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
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
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5, 5};

    int singleElement = singleNonDuplicate(arr);

    cout << "The element that appears only once is: " << singleElement << endl;

    return 0;
}