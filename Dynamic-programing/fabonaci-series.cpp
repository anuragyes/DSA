// #include <iostream>
// using namespace std;

// //  using recurssion 

//  int fab(int n){
//     if(n == 0) return 0 ;
//      if(n == 1) return 1;

//      return fab(n-1)+fab(n-2); 
//  }

//  int main(){
//       cout<< fab(10);
//      return 0;
//  }

// //   using dynamic programming
// //  using dynamic programming 
//  int find(int n , vector<int>&store){
//     //   base case  
//     if(n<=1){
//          return n;
//     }
//     //  Already answer stored 
//      if(store[n]!=-1) return store[n];
     
//       store[n] = (find(n-1,store)+find(n-2,store))%1000000007;
      
//        return store[n];
//  }

// int nthFibonacci(int n){
//     //  make a vector t0 store previous answers
//      vector<int>store(n+1,-1);
     
//       return find(n,store);
//     }
// }; 
