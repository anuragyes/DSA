 int left = 0, right = 0;
    long sum = 0, maxSum = 0;

    // Move the right pointer using a while loop
    while (right < N) {
        sum += Arr[right];  // Add the current element to the sum

        // Check if the window has reached size K
        if (right - left + 1 == K) {
            maxSum = max(maxSum, sum);  // Update the maximum sum if needed

            // Shrink the window by removing the element at 'left'
            sum -= Arr[left];
            left++;  // Slide the window
        }
        
        right++;  // Move the right pointer to expand the window
    }

    return maxSum;

    /*N = 4, K = 2
Arr = [100, 200, 300, 400]
Output:
700
Explanation:
Arr3  + Arr4 =700,
which is maximum.*/