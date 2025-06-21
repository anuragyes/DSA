#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        int n = str.length();
        
        // Reverse the entire string first
        reverse(str.begin(), str.end());
        
        int start = 0;
        
        // Reverse each word individually
        for (int i = 0; i <= n; i++) {
            // When we hit a '.' or the end of the string
            if (i == n || str[i] == '.') {
                reverse(str.begin() + start, str.begin() + i);
                start = i + 1;  // Move to the next word
            }
        }
        
        return str;
    }
};
