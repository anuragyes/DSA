/*Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.*/
/*Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
/*class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int left = 0; // Left boundary of the sliding window
    int zeroCount = 0; // Count of zeroes in the current window
    int maxi = 0; // Maximum length of subarray found

    // Sliding window approach
    for (int i = 0; i < nums.size(); ++i) {
        // If we encounter a zero, increase the zero count
        if (nums[i] == 0) {
            zeroCount++;
        }

        // If the count of zeroes exceeds k, move the left boundary of the window
        while (zeroCount > k) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }

        // Update the maximum length of the subarray found
        maxi = max(maxi, i - left + 1);
    }

    return maxi;
    }
};