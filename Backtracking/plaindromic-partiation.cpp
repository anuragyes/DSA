#include <vector>
#include <string>   
using namespace std;


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        backtrack(s, 0, 0, temp, ans);
        return ans;
    }

private:
    // Check if substring s[left..right] is a palindrome
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    // Simulate loop by recursion: index is current start, i is end of current substring
    void backtrack(const string& s, int index, int i, vector<string>& temp, vector<vector<string>>& ans) {
        if (index == s.size()) {
            ans.push_back(temp);
            return;
        }

        if (i == s.size()) return; // end of the string, return

        if (isPalindrome(s, index, i)) {
            temp.push_back(s.substr(index, i - index + 1));       // include substring
            backtrack(s, i + 1, i + 1, temp, ans);                 // move both index and i forward
            temp.pop_back();                                      // backtrack
        }

        backtrack(s, index, i + 1, temp, ans);  // try next i (simulating loop)
    }
};










// class Solution {
// public:
//     vector<string> temp;

//     bool isPlindrome() {
//         if (start > end)
//             return false;

//         while (start < end) {
//             if (s[start] != s[end]) {
//                 return false;
//             }

//             start++;
//             end--;
//         }
//          return false;
//     }


 bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void backtracking(vector<vector<string>>&ans , string s, int   start, vector<string>& temp) {
        if (start == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end )) {
                temp.push_back(s.substr(start, end - start + 1));
                backtracking(s, end  + 1, ans, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        backtracking(s, ans, 0);
        return ans;
    }
