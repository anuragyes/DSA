class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        // second optimal approch 
    int n = nums.size();
    vector<long long int> ans(n, 1);
    vector<long long int> prefixSum(n, 1);
    vector<long long int> sufixSum(n, 1);

    // Calculate prefix products
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] * nums[i - 1];
    }

    // Calculate suffix products
    for (int i = n - 2; i >= 0; i--) {
        sufixSum[i] = sufixSum[i + 1] * nums[i + 1];
    }

    // Calculate final answer by multiplying prefix and suffix products
    for (int i = 0; i < n; i++) {
        ans[i] = prefixSum[i] * sufixSum[i];
    }

    return ans;
      
      
      
        //  first optimal approch
        /*
    vector<long long int> ans;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = n - 1;
        long long int product = 1;
        
        while (left <= right) {
            if (left != i) {
                product *= nums[left];
            }
            if (right != i && right != left) {
                product *= nums[right];
            }
            left++;
            right--;
        }
        
        ans.push_back(product);
    }
    
    return ans;
    */
        
        
         
        
        
        
        
        // brute force approch 
      /*
       vector<long long int>ans;
       for(int i =0;i<nums.size();i++){
        long long int product = 1;
           for(int j = 0;j<nums.size();j++){
               if(i!=j)
                   product = product*nums[j];
               
               
           }
           ans.push_back(product);
       }
        return ans;
        */
    }
};
