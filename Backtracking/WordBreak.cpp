// s = "applepenapple", wordDict = ["apple","pen"]  
#include <bits/stdc++.h>
#include <string>
#include<unordered_set>
using namespace std ;

class Solution {
public:
    bool backtrack(string s, unordered_set<string>& dict, vector<int>& memo, int start) {
        if(start == s.size()) return true;
        if(memo[start] != -1) return memo[start];

        for(int end = start+1; end <= s.size(); end++){
            if(dict.count(s.substr(start, end - start)) && backtrack(s, dict, memo, end)){
                memo[start] = 1;
                return true;
            }
        }

        memo[start] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1); // -1: unvisited, 0:false, 1:true
        return backtrack(s, dict, memo, 0);
    }
};
