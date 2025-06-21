#include <iostream>
using namespace std;
#include <map>
#include <string>
#include <unordered_map>
// int main()
// {
//     string str("Some");
//     string s = "kelea4";
//     cout << s.back();
// }

class Solution {
public:
    int longestPalindrome(string s) {
        int lowercase[26] = {0};
        int uppercase[26] = {0};
         bool odd = 0 ;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch >= 'a') {
                lowercase[ch - 'a']++;
            } else {
            uppercase[ch - 'A']++;
            }
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (lowercase[i] % 2 == 0) {
                count = count + lowercase[i];
            } else  {
                count = count + lowercase[i]-1;
                 odd = 1;
            }

            if (uppercase[i] % 2 == 0) {
                count = count + uppercase[i];
            } else  {
                count = count + uppercase[i]-1;
                 odd = 1;
            }
        }
         return count + odd;
    }
};