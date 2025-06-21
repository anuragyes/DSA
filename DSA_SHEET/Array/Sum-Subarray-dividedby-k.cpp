class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        // optimal approch 
   
         int step = 0 , rem;
         unordered_map<int, int> m;
         m[0]=1;
         int preSum =0;
         for(int i =0;i<arr.size();i++)
         {
            preSum = preSum+arr[i];
             rem = preSum%k;
            //   if rem is negative , make it postive 
             if(rem<0){
                 rem = k+rem;
             }

           if(m.count(rem)){
            step += m[rem];
            m[rem]++;
           }else{
             m[rem] = 1;
           }

         }
          return step;

        //   brute force approch 
        // int count = 0;

        // for (int i = 0; i < arr.size(); i++) {
        //     int sum = 0;
        //     for (int j = i; j < arr.size(); j++) {
        //         sum = sum + arr[j];
        //         if (sum % k == 0)
        //             count++;
        //     }
        // }
        // return count;
    }
};