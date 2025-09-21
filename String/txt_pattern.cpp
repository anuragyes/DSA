#include <bits/stdc++.h>
using namespace std;

// Recursive backtracking function
void findPattern(string &text, string &pattern, int idx, vector<int> &result) {
    int n = text.size();
    int m = pattern.size();

    // Base case: if remaining text is smaller than pattern, stop
    if (idx > n - m) return;

    // Check if pattern matches starting at index idx
    bool match = true;
    for (int i = 0; i < m; i++) {           // start from 0
        if (text[idx + i] != pattern[i]) { // add idx
            match = false;
            break;
        }
    }

    if (match) {
        result.push_back(idx + 1); // 1-based indexing
    }

    // Recur for next index
    findPattern(text, pattern, idx + 1, result);
}

// Wrapper function
vector<int> stringMatch(string text, string pattern) {
    // vector<int> result;
    // findPattern(text, pattern, 0, result);
    // return result;

    vector<int> result;
    int n = text.size();
    int m = pattern.size();

    // Iterate over each possible starting index
    for (int i = 0; i <= n - m; i++) {
        bool match = true;

        // Check if pattern matches starting at index i
        for (int j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            result.push_back(i + 1); // 1-based indexing
        }
    }

    return result;
}


/*You’re given two strings, 'text' of length 'n' and 'pattern' of length 'm', consisting of lowercase characters.



Find all the occurrences of the string ‘pattern’ in ‘text’.



For each occurrence, print the index from where it starts in the string ‘text’ (1 - indexed).



Example:
Input: ‘text’ = “cxyzghxyzvjkxyz” and ‘pattern’ = “xyz”

Output: 2 7 13

Explanation: The pattern ‘pattern’ = “xyz” appears at 3 positions in ‘text’.*/