#include <bits/stdc++.h>
using namespace std;

bool canPartition(int index, vector<int> &arr, vector<int> &subsetSum, int target, int K)
{
    if (index == arr.size())
    {
        for (int i = 0; i < K; ++i)
            if (subsetSum[i] != target)
                return false;
        return true;
    }

    for (int i = 0; i < K; ++i)
    {
        if (subsetSum[i] + arr[index] <= target)
        {
            subsetSum[i] += arr[index];

            if (canPartition(index + 1, arr, subsetSum, target, K))
                return true;
            //    backtrack 
            subsetSum[i] -= arr[index];
        }

        // Optimization: avoid duplicate subsets
        if (subsetSum[i] == 0)
            break;
    }

    return false;
}

bool splitArray(vector<int> &arr, int K)
{
    int N = arr.size();
    if (K > N)
        return false;

    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if (totalSum % K != 0)
        return false;

    int target = totalSum / K;
    sort(arr.rbegin(), arr.rend()); // Start from largest to help pruning

    vector<int> subsetSum(K, 0);
    return canPartition(0, arr, subsetSum, target, K);
}

/*#include <bits/stdc++.h>


  bool backtracking(vector<int>&ans,vector<bool>&used, int k , int start, int currentsum, int target ){
       if(k==1) return true;
       if(currentsum==target){
       return backtracking(ans,used,k-1,0,0,target);
       }

         for(int i= start;i<ans.size();i++){
            if(!used[i] && currentsum+ans[i]<=target){
               used[i] = true;
               if(backtracking(ans,used,k,i+1,currentsum+ans[i],target)){
                  return true;
               }
                used[i]=false;
            }
         }

         return false;
  }
bool splitArray(vector<int> &arr, int K) {
    //  edge case
     if(K<=0)  return false;

    // step first  if totals sum divided by k equal to zero means divisible

     int totalSum = accumulate(arr.begin(),arr.end(),0);

    //    avoid to duplicate thats why we are useing bool vector
     vector<bool>used(arr.size(),false);
    //    using backtracking
     if(totalSum%K!=0)  return false;
     int target = totalSum/K;
     sort(arr.rbegin(),arr.rend());


          return backtracking(arr,used, K,0,0,target);





}*/