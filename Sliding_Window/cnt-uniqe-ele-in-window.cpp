/*class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
    unordered_map<int, int> m;
    vector<int> ans;
    
    // Fill the map with the first 'k' elements
    for (int i = 0; i < k; i++) {
        m[A[i]]++;
    }
    
    ans.push_back(m.size()); // Store the count of distinct elements for the first window
    
    int j = 0; // This keeps track of the left side of the window
    
    // Iterate through the rest of the array, starting from index 'k'
    for (int i = k; i < n; i++) {
        // Decrease the count of the element going out of the window
        m[A[j]]--;
        
        // If the count becomes 0, erase the element from the map
        if (m[A[j]] == 0) {
            m.erase(A[j]);
        }
        
        // Add the new element entering the window
        m[A[i]]++;
        
        // Add the distinct count of the current window to the result
        ans.push_back(m.size());
        
        j++; // Move the left side of the window forward
    }
    
    return ans;
    
    
    }
};
*//**/


/*Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.*/