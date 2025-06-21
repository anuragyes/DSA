/*K Sized Subarray Maximum*/
/*N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6*/


/*class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
          vector<int> ans;
    deque<int> dq;  // To store the indices of useful elements in the current window

    // Process the first window of k elements
    for (int i = 0; i < k; ++i) {
        // Remove elements smaller than the current element from the deque
        //  remove smallest element until greater element will not comes in the range  of   0 -> k 
        while (!dq.empty() && arr[dq.back()] <= arr[i]){
            dq.pop_back();
        }
            
            //  put  indecies  push into dequeue 
        dq.push_back(i);
    }

    // Process the rest of the elements
    for (int i = k; i < n; ++i) {
        // The front of the deque contains the index of the largest element in the previous window
        ans.push_back(arr[dq.front()]);

        // Remove the elements that are out of this window
        while (!dq.empty() && dq.front() <= i - k){
            dq.pop_front();
        }

        // Remove elements smaller than the current element from the deque
        while (!dq.empty() && arr[dq.back()] <= arr[i]){
            dq.pop_back();
        }
   //  put  indecies  push into dequeue 
        dq.push_back(i);
    }

    // Add the maximum of the last window
    ans.push_back(arr[dq.front()]);

    return ans;
    }
};
*/