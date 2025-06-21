/*// using dynamic programing

  class Solution {
public:
    int solve(int n, vector<int>& dp) {
        //  base case
        if (n <= 1)
            return 1;
        if (dp[n] != -1) {
            return dp[n];
        }
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            sum += solve(i - 1 , dp) * solve(n - i , dp);
        }
        return dp[n]= sum;
    }
    int numTrees(int n) {
         vector<int>dp(n+1,-1);
          return solve(n,dp);
    }
};


// using recursion

class Solution {
public:
    int numTrees(int n) {
         //  base case
        if (n <= 1)
            return 1;

        int sum = 0;
  //  thing assume every i node make root node
        for (int i = 1; i <= n; i++) {
            sum += numTrees(i-1)*numTrees(n-i);
        }
         return sum;
    }
};*/