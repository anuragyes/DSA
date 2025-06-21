class Solution {
  public:

//    Easy method 
    int rotateDelete(vector<int> &arr) {
       int n = arr.size();
       int  k = 1;
        while(n>1){
            arr.insert(arr.begin(),arr.back());
            arr.pop_back();
            
             if(n<k){
                 arr.erase(arr.begin());
             }else{
                 
             
            
            arr.erase(arr.end()-k);
             }
            n = arr.size();
            k++;
        }
         return arr[0];
    }
};




//   little difficult 

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
         int k = 1; // Initialize step for deletion
        while (arr.size() > 1) {
            // Rotate array by 1 (clockwise)
            rotate(arr.begin(), arr.end() - 1, arr.end());
            
            // Calculate position to delete: k-th from end
            int deleteIdx = arr.size() - k;
            
            // Adjust deleteIdx if it's out of bounds
            if (deleteIdx < 0) deleteIdx = 0;
            
            // Delete the element
            arr.erase(arr.begin() + deleteIdx);
            
            // Increment k for next deletion
            k++;
        }
        // Return the last remaining element
        return arr[0];
    }
};