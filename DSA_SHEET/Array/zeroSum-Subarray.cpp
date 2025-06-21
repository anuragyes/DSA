class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        // optimal approch 
         long long int count = 0;
    unordered_map<long long int, long long int> m;
    long long int prefixSum = 0;

    // Edge case when array is empty
    if (arr.empty()) {
        return 0;
    }

    m[0] = 1;  // Initialize the map with prefix sum 0 with a count of 1

    for (size_t i = 0; i < arr.size(); ++i) {
        prefixSum += arr[i];

        // Check if the current prefixSum has been seen before
        if (m.count(prefixSum)) {
            count += m[prefixSum];
        }

        // Increment the count for the current prefixSum in the map
        m[prefixSum]++;
    }

    return count;
      
      
        // brute force approch  n^3 time complexcity
    
    //   int count =0;
    //   for(int i =0;i<n;i++){
         
    //         for(int j =i ; j<n;j++){
    //               int sum =0;
    //           for(int k = i;k<=j;k++) {
    //               sum = sum+arr[k]; 
    //           }
    //             if(sum == 0) count++;
    //         }
    //   }
    //     return count;
    //   second brute force approch and time complexcity is n^2
    
    // int count=0;
    //  for(int i =0;i<n;i++){
    //       int sum =0;
          
    //      for(int j = i;j<n;j++){
    //          sum = sum+arr[j];
             
    //          if(sum ==0 ) count++;
    //      }
         
    //  }
    //  return count;
    }
};