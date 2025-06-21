class Solution {
public:
   int maxScore(vector<int>& arr, int k) {
    int left = 0;
    int right = arr.size() - 1;  // Start right from the end of the array

    int leftsum = 0;
    int rightsum = 0;
    int maxi = 0;

    // Calculate the sum of the first k elements from the left
    for (int i = 0; i < k; i++) {
        leftsum += arr[i];
        left++;
    }

    maxi = leftsum;

    // Now shift elements from the left sum to the right sum
    while (left > 0) {
        left--;  // Move the left pointer backwards
        leftsum -= arr[left];  // Subtract from the left sum
        rightsum += arr[right];  // Add to the right sum
        right--;  // Move the right pointer backwards
        maxi = max(maxi, leftsum + rightsum);  // Update the maximum score
    }

    return maxi;
   }
};

/*There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.*/