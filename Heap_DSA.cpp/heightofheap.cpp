#include <bits/stdc++.h> 
class Solution{
public:
    int heapHeight(int N, int arr[]){
        
        
        //  if size = 1 return 1;
          if(N == 1){
               return 1;
          }
        
        
        
        // ans for store 
          int ans = 0;
         while(N > 1){
              ans++;
               N/=2;
         }
          return ans ;
    }
};