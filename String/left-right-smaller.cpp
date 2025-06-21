// #include <iostream>
// #include <stack>
// #include <math.h>
// #include <vector>
// using namespace std;
// /*
// class Solution {
//   public:
//     /*You are required to complete this method */
//    vector<int> leftsmall(vector<int> &arr,int n){
//         stack<int> st;
//         vector<int> ans(n,0);
//         st.push(arr[0]);
        
//         for(int i=1;i<n;i++){
//         while(!st.empty() && st.top()>=arr[i])
//         st.pop();
        
//         if(st.empty())
//         ans[i]=0;
        
//         else
//         ans[i]=st.top();
        
//         st.push(arr[i]);
            
//         }
        
//         return ans;
//     }
    
//     vector<int> rightsmall(vector<int> &arr,int n){
//         stack<int> st;
//         vector<int> ans(n);
//         st.push(0);
        
//         for(int i=n-1;i>=0;i--){
//             while(st.top()!=0 && st.top()>=arr[i])
//             st.pop();
            
//             ans[i]=st.top();
            
//             st.push(arr[i]);
//         }
        
//         return ans;
        
//     }
    
//     int findMaxDiff(vector<int> &arr, int n) {
        
//         vector<int> lsmaller=leftsmall(arr,n);
//         vector<int> rsmaller=rightsmall(arr,n);
//         // int maxi=INT_MIN;
//         for(int i=0;i<n;i++){
            
//             int diff=abs(lsmaller[i]-rsmaller[i]);
            
//             maxi=max(maxi,diff);
            
//         }
        
//         return maxi;
//     }
// // }
// // */