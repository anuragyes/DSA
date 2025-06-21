#include <iostream>
using namespace std;
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        // make a min heap 
         priority_queue<long long , vector<long long>,greater<long long> >pq;
        //   push all the element into min heap 
          for(int i=0;i<n;i++){
               pq.push(arr[i]);
          }
          
         long long  ans = 0;
        //  condition given by  question 
         while(pq.size()>1){
   long long  a = pq.top();      
             pq.pop();
             
             
      long long  b = pq.top();
             pq.pop();
             
             
             long long  sum = a+b;
             
             ans += sum;
              
              pq.push(sum);
             
         }
          return ans;
         
    }
};


//{ Driver Code Starts.

int main() {
   
    return 0;
}

