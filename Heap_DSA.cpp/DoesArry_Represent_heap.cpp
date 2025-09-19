
class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
         // check all internal nodes
        // for (int i =0;i<n; i++) {  this is also right 
         for (int i =n/2-1;i>=0; i--) {  // her some optimisaltion leaf node dont check it 
            int left = 2*i + 1;
            int right = 2*i + 2;

            // if left child exists and is greater than parent
            if (left < n && arr[i] < arr[left])
                return false;

            // if right child exists and is greater than parent
            if (right < n && arr[i] < arr[right])
                return false;
        }
        return true;
    }
};