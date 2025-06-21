#include <iostream>
using namespace std;

int find(int nums[], int size, int target)
{

    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[start] <= nums[mid])
        {
            if (nums[start] <= target && target <= nums[mid])
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
            if (nums[mid] <= target && target <= nums[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
};

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2, 3};
    int size = 8;
    int target = 0;
    cout << find(arr, size, target);
    return 0;
}