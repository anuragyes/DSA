
#include  <bits/stdc++.h>>


vector<int> printMatrix(vector<vector<int>> &mat, int n, int m)
{
     vector<int>ans;
   for(int i =0;i<n+m;i++){
       vector<int>temp;
        int r = (i<m) ? 0: i-m+1;
        int c = (i<m) ? i: m-1;
         while(r<n && c>=0){
             temp.push_back(mat[r][c]);
             r++;
             c--;
         }
          if(i%2==0)  reverse(temp.begin(),temp.end());

           for(int x: temp){
      ans.push_back(x);
           }

   }
    return ans;
}







