// class Solution{
//   public:
//   int smallestSumSubarray(vector<int>& arr){
//        int length = arr.size();
//       int mini=INT_MAX;
//         int sum=0;
//         for(int i=0;i<length;i++){
//             sum+=arr[i];
//              mini = min(mini,sum);
//             if(sum>0) sum=0;
//         }
//         return mini;
//   }
// };