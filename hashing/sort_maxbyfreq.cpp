#include <iostream>
using namespace std;


class Solution {
public:

     static  bool cmp(pair<char,int>&a , pair<char,int>&b) {
        return a.second > b.second ; 
    }
    string frequencySort(string s) {
                  map<char,int>m ; 
        int n = s.length() ; 
        for(int i = 0 ; i < n ; i++){
            m[s[i]]++ ; 
        }
        vector<pair<char , int>> vec(m.begin() , m.end()) ; 
        sort(vec.begin() , vec.end() , cmp) ;
           
        
        string temp = "" ; 
        for(auto &it : vec){
            int freq = it.second ; 
            for(int j = 0 ; j < freq ; j++){
           temp += it.first ;  
            }
        }
        return temp ; 

    }

};