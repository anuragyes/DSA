#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixSumCount;  // To store prefix sums and their counts
        int sum = 0;
        int count = 0;

        prefixSumCount[0] = 1;  // Initial prefix sum is 0, and it has occurred once

        for (int num : nums) {
            sum += num;  // Update the current prefix sum

            // If (sum - goal) has been seen before, it means there is a subarray that sums to the goal
            if (prefixSumCount.find(sum - goal) != prefixSumCount.end()) {
                count += prefixSumCount[sum - goal];
            }

            // Increment the count of the current prefix sum in the map
            prefixSumCount[sum]++;
        }

        return count;
    }
};
/*Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 */

//  second approch 
class Solution {
  public:
  int solve(vector<int>& arr, int n, int target) {
        int l=0,r=0,count=0,sum=0;
        if(target<0) return 0;
        while(r<n) {
            sum += arr[r];
            while(sum>target) {
                sum -= arr[l];
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
  
   
    int numberOfSubarrays(vector<int>& arr, int target) {
        int N = arr.size();
          return solve(arr,N,target) - solve(arr,N,target-1);
    }
};