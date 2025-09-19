// Apply Operations to Make String Empty

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     vector<string> ans;

//     string solve(string s) {
//         if (s.empty()) {
//             return ans.back(); // last non-empty string
//         }

//         unordered_set<char> seen;
//         string temp = "";  // leftover after this round
//         string res = "";   // result after this round

//         for (char c : s) {
//             if (seen.find(c) == seen.end()) {
//                 seen.insert(c); // remove first occurrence
//             } else {
//                 temp += c; // keep for next round
//             }
//             res += c;
//         }

//         ans.push_back(res);
//         return solve(temp);
//     }

//     string lastNonEmptyString(string s) {
//         return solve(s);
//     }
// };

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lastNonEmptyString(string s) {
        // int n = s.size();
        // vector<int> freq(26, 0), last(26, -1);

        // // count frequencies and last occurrences
        // for (int i = 0; i < n; i++) {
        //     freq[s[i] - 'a']++;
        //     last[s[i] - 'a'] = i;
        // }

        // // find maximum frequency
        // int maxFreq = *max_element(freq.begin(), freq.end());

        // // collect characters that reach max frequency, in order of last
        // // occurrence
        // string result;
        // for (int i = 0; i < n; i++) {
        //     int c = s[i] - 'a';
        //     if (freq[c] == maxFreq && last[c] == i) {
        //         result.push_back(s[i]);
        //     }
        // }
        // return result;

      int n = s.size();
    vector<int> arr(n);          // store frequency of each character at its index
    unordered_map<char,int> maap; // frequency counter

    for (int i = 0; i < n; i++) {
        maap[s[i]]++;
        arr[i] = maap[s[i]]; // store the current freq of s[i]
    }

    int maxFreq = *max_element(arr.begin(), arr.end());

    string ans = "";
    for (int i = 0; i < n; i++) {
        if (arr[i] == maxFreq) {
            ans += s[i];
        }
    }

    return ans;
    }
};