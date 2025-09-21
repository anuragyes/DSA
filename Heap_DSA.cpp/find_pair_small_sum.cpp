#include <bits/stdc++.h> 
 using node = pair<int,pair<int,int>>;
vector<vector<int>> findPairs (int n, int m, vector<int> &arr1, vector<int> &arr2, int k)
{
    
priority_queue<node,vector<node>,greater<node>>q;

vector<vector<int>>ans ;

 for(int i=0;i<n;i++){
   q.push({arr1[i]+arr2[0],{i,0}});
 }

  while(!q.empty() && k--){
    auto top = q.top();
    q.pop();
     int i = top.second.first;
      int j = top.second.second;

       ans.push_back({arr1[i],arr2[j]});

        if(j+1<m){
          q.push({arr1[i]+arr2[j+1],{i,j+1}});
        }
  }

  return ans;
}


// You are given two arrays of positive integers say ‘arr1’ and ‘arr2’ and a positive integer ‘K’. Also ‘arr1’ and ‘arr2’ are already sorted in ascending order. Consider all pairs (x, y) such that ‘x’ belongs to ‘arr1’ and ‘y’ belongs to ‘arr2’. You need to find exactly ‘K’ such pairs with the smallest sum of ‘x’ and ‘y’.

// Example:

// Let ‘arr1’ be [ ‘1’, ‘2’, ‘6’ ] and ‘arr2’ be [ ‘3’, ‘3’, ‘5’ ] and ‘K’ be 3.

// There are 9 possible (x, y) pairs such that ‘x’ belongs to ‘arr1’ and ‘y’ belongs to ‘arr2’. Among all of them 3 pairs with smaller ‘x’ + ‘y’ are [ (1, 3), (1, 3), (2, 3) ].