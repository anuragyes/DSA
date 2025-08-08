


// Magnetic Force Between Two Balls and aggrsive cow are two problems that can be solved using binary search on the answer. The idea is to find the maximum minimum distance between cows or balls placed in stalls.  BOTH ARE SAME PROBLEM










class Solution {
public:
 bool ispossible(vector<int> &stalls, int k ,int n , int mid) {
        int cow = 1;  // First cow at the first stall
        int lastindex = stalls[0];  // The position of the last placed cow
        for(int i = 1; i < n; i++) {  // Start from the second stall
            if((stalls[i] - lastindex) >= mid) {  // Check if the distance is at least 'mid'
                cow++;  // Place a cow here
                lastindex = stalls[i];  // Update the position of the last placed cow
            }
            if(cow == k) return true;  // If all cows are placed, return true
        }
        return false;  // If not all cows could be placed, return false
   }
    int maxDistance(vector<int>& stalls, int k) {
       int n = stalls.size();
        sort(stalls.begin(), stalls.end());  // Sort the stall positions
        
        int start = 1;  // Minimum possible distance between cows
        int end = stalls[n-1] - stalls[0];  // Maximum distance between first and last stall
        int ans = 0;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;  // Calculate mid point
            
            if(ispossible(stalls, k, n, mid)) {
                ans = mid;  // This distance is possible, so we try for a bigger distance
                start = mid + 1;
            } else {
                end = mid - 1;  // This distance is not possible, so we try a smaller distance
            }
        }
        
        return ans; 
    }
};