#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int partition(std::vector<int> &nums, int left, int right)
{
    int pivot = nums[right];
    int i = left - 1;

    for (int j = left; j < right; ++j)
    {
        if (nums[j] <= pivot)
        {
            ++i;
            std::swap(nums[i], nums[j]);
        }
    }
    std::swap(nums[i + 1], nums[right]);
    return i + 1;
}

int quickSelect(std::vector<int> &nums, int left, int right, int k)
{
    if (left == right)
        return nums[left];

    int pivotIndex = partition(nums, left, right);

    int kthLargestIndex = nums.size() - k;

    if (pivotIndex == kthLargestIndex)
    {
        return nums[pivotIndex];
    }
    else if (pivotIndex < kthLargestIndex)
    {
        return quickSelect(nums, pivotIndex + 1, right, k);
    }
    else
    {
        return quickSelect(nums, left, pivotIndex - 1, k);
    }
}

int findKthLargest(std::vector<int> &nums, int k)
{
    if (k <= 0 || k > nums.size())
    {
        return -1; // Invalid k
    }

    return quickSelect(nums, 0, nums.size() - 1, k);
}

int main()
{
    std::vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int k = 2; // Find the 3rd largest element

    int kthLargest = findKthLargest(nums, k);
    if (kthLargest != -1)
    {
        std::cout << "The " << k << "th largest element is: " << kthLargest << std::endl;
    }
    else
    {
        std::cout << "Invalid input." << std::endl;
    }

    return 0;
}
