

#include <iostream>
#include <vector>
#include <unordered_map>  
#include <cmath>
using namespace std;
// Problem: Given an array of characters where 'P' represents police and 'T' represents thieves, find the maximum number of thieves that can be caught by the police within a given distance k.
  

class Solution {
public:
    int catchThieves(vector<char>& arr, int k) {
        int n = arr.size();
        vector<int> police, thief;
        
        // Store positions of police and thieves
        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P')
                police.push_back(i);
            else if (arr[i] == 'T')
                thief.push_back(i);
        }

        int i = 0, j = 0, count = 0;
        
        // Try to catch thieves with police within k range
        while (i < police.size() && j < thief.size()) {
            if (abs(police[i] - thief[j]) <= k) {
                count++;
                i++;
                j++;
            } else if (thief[j] < police[i]) {
                j++;
            } else {
                i++;
            }
        }

        return count;
    }
};

