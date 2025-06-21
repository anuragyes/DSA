// Find the closest pair from two arrays  asked in google
#include <vector>
class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
     // Ensure both arrays are sorted
       int left = 0;        // Pointer for arr[]
    int right = m - 1;   // Pointer for brr[]
    int diff = INT_MAX;  // Track the smallest difference
    int a = 0, b = 0;    // Variables to store the closest pair

    // Iterate with two pointers until they cross
    while (left < n && right >= 0) {
        int sum = arr[left] + brr[right];

        // Check if this is the closest pair so far
        if (abs(sum - x) < diff) {
            a = arr[left];
            b = brr[right];
            diff = abs(sum - x);
        }

        // Move pointers based on comparison with X
        if (sum > x) {
            right--;  // Decrease sum by moving the pointer in brr[]
        } else {
            left++;   // Increase sum by moving the pointer in arr[]
        }
    }

    // Return the result as a vector containing the closest pair
    return {a, b};
    }
};


Input : N = 4, M = 4
arr[ ] = {1, 4, 5, 7}
brr[ ] = {10, 20, 30, 40} 
X = 32
Output : 
1, 30