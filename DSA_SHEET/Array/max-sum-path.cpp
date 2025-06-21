/*Given two sorted arrays of distinct integers arr1 and arr2. Each array may have some elements in common with the other array. Find the maximum sum of a path from the beginning of any array to the end of any array. You can switch from one array to another array only at the common elements.

Note:  When we switch from one array to other,  we need to consider the common element only once in the result.*/


class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
         int i = 0, j = 0, sum1 = 0, sum2 = 0, ans = 0;
        
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j]) {
                sum1 += arr1[i++];
            } else if (arr1[i] > arr2[j]) {
                sum2 += arr2[j++];
            } else {
                ans += max(sum1, sum2) + arr1[i];
                i++;
                j++;
                sum1 = 0;
                sum2 = 0;
            }
        }
        
        // Process remaining elements in arr1
        while (i < arr1.size()) {
            sum1 += arr1[i++];
        }
        
        // Process remaining elements in arr2
        while (j < arr2.size()) {
            sum2 += arr2[j++];
        }
        
        ans += max(sum1, sum2);
        
        return ans;
    }
};