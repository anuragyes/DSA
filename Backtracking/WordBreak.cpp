// s = "applepenapple", wordDict = ["apple","pen"]  
#include <bits/stdc++.h>
#include <string>
#include<unordered_set>
using namespace std ;
//   uisng little bit dp 
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


//   without dp just use backtrcaking or recursion 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function to try all substrings
    bool backtrack(string &s, unordered_set<string> &dict, int start) {
        if(start == s.size()) return true;  // reached end, valid segmentation

        // Try every substring starting at 'start'
        for(int end = start + 1; end <= s.size(); end++) {
            string sub = s.substr(start, end - start);
            if(dict.count(sub)) { // substring is in wordDict
                if(backtrack(s, dict, end)) return true; // recursively check rest
            }
        }

        return false; // no valid segmentation
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return backtrack(s, dict, 0);
    }
};
