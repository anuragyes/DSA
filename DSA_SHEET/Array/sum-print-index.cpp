

/*Given an unsorted array arr of size n that contains only non negative integers, find a sub-array (continuous elements) that has sum equal to s. You mainly need to return the left and right indexes(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right. If no such subarray exists return an array consisting of element -1.*/


/*class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
       int leftIndex=0, rightIndex=0, sum=0;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
            if(sum>=s){
                rightIndex=i;
            }
        
        while(sum>s && leftIndex<rightIndex){
            sum = sum-arr[leftIndex];
            leftIndex++;
        }
        if(sum==s){
            return{leftIndex+1, rightIndex+1};
        }
        
        }
        
        return {-1};
    }
};*/