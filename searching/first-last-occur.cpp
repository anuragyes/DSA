/*class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        vector<int> result(2, -1);
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) {
                if (result[0] == -1) {
                    result[0] = i;
                }
                result[1] = i;
            }
        }
        return result;
    }
};*/

//  second wasy
/*class Solution {
public:
   int firstOcc(vector<int>& arr, int target) {
       int start = 0;
       int end = arr.size() - 1;
       int ans = -1;
       int mid = start + (end - start) / 2;
       while (start <= end) {
           if (arr[mid] == target) {
               ans = mid;
               end = mid - 1;
           } else if (target > arr[mid]) {
               start = mid + 1;
           } else if (target < arr[mid]) {
               end = mid - 1;
           }
           mid = start + (end - start) / 2;
       }
       return ans;
   }

   int lastOcc(vector<int>& arr, int target) {
       int start = 0;
       int end = arr.size() - 1;
       int ans = -1;
       int mid = start + (end - start) / 2;
       while (start <= end) {
           if (arr[mid] == target) {
               ans = mid;
               start = mid + 1;
           } else if (target > arr[mid]) {
               start = mid + 1;
           } else if (target < arr[mid]) {
               end = mid - 1;
           }
           mid = start + (end - start) / 2;
       }
       return ans;
   }

   vector<int> searchRange(vector<int>& nums, int target) {
       return {firstOcc(nums, target), lastOcc(nums, target)};
   }
};
*/