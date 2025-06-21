#include <iostream>
#include <vector>
using namespace std;

//  optimal approch 

 bool check(vector<int>arr){
     int n = arr.size();
    int totalSum=0;

    for(int i =0;i<n;i++){
         totalSum = totalSum+arr[i];
    } 
     int prefix = 0;

     for(int i =0;i<n-1;i++){
        
        prefix = prefix+arr[i];
         
          int ans = totalSum - prefix;
          if(ans==totalSum) return 1;
     }
      return 0;
 }


//  first approch 
// bool check(vector<int> arr)
// {
//     int n = arr.size();
//     for (int i = 0; i < n - 1; i++)
//     {
//         int sum1 = 0;
//         int sum2 = 0;
//         for (int j = 0; j <= i; j++)

//             sum1 = sum1 + arr[j];
//         for (int k = i + 1; k < n; k++)

//             sum2 = sum2 + arr[k];
//         if (sum1 == sum2)
//             return true;
//     }
//     return false;
// }

int main()
{
    vector<int> arr = {3, 4, -2, 5, 8, -20, 10, 8};
    cout << check(arr);
    return 0;
}