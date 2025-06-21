#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool subarraySumEqualK(const vector<int>& nums, int k) {
    unordered_map<int, int> sumMap; // Map to store cumulative sum and its index
    sumMap[0] = -1; // Handle case when the sum equals k at the beginning
    
    int cumulativeSum = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        cumulativeSum += nums[i];  // Update cumulative sum
        
        // Check if there is a previous sum such that cumulativeSum - previousSum = k
        if (sumMap.find(cumulativeSum - k) != sumMap.end()) {
            // If found, return true as we found the subarray
            cout << "Subarray found between indices " 
                 << sumMap[cumulativeSum - k] + 1 << " and " << i << endl;
            return true;
        }
        
        // Store the cumulative sum in the map
        sumMap[cumulativeSum] = i;
    }
    
    return false; // Return false if no subarray is found
}

int main() {
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;
    
    if (!subarraySumEqualK(nums, k)) {
        cout << "No subarray with sum " << k << " found." << endl;
    }
    
    return 0;
}
