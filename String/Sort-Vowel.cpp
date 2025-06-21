Given a 0-indexed string s, permute s to get a new string t such that:

All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
Return the resulting string.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.
//     bool isVowel(char c) {
//         return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
//                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
//     }
//     string sortVowels(string s) {
//         //  make a vector
//         vector<char> vowels;

//         // Collect vowels from the input string
//         for (char c : s) {
//             if (isVowel(c)) {
//                 vowels.push_back(c);
//             }
//         }

//         // Sort the collected vowels  by theri ASCLLC values
//        sort(vowels.begin(), vowels.end());

//         // Replace vowels in the original string with sorted vowels
//         int index = 0;
//         for (int i = 0; i < s.length(); i++) {
//             if (isVowel(s[i])) {
//                 s[i] = vowels[index++];
//             }
//         }

//         return s;
//     }
// };

class Solution {
public:
    string sortVowels(string s) {
        vector<int> uppercase(26, 0); // Count of uppercase vowels
        vector<int> lowercase(26, 0); // Count of lowercase vowels

        // Count the vowels and replace them with '#'
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                lowercase[s[i] - 'a']++;
                s[i] = '#';
            } else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                uppercase[s[i] - 'A']++;
                s[i] = '#';
            }
        }

        // Sort uppercase vowels first, then lowercase vowels
        string sortedVowels;

        for (int i = 0; i < 26; i++) {
            char c = 'A' + i;
            while (uppercase[i] > 0) {
                sortedVowels += c;
                uppercase[i]--;
            }
        }

        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            while (lowercase[i] > 0) {
                sortedVowels += c;
                lowercase[i]--;
            }
        }

        // Replace '#' in the original string with sorted vowels
        int vowelIndex = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                s[i] = sortedVowels[vowelIndex++];
            }
        }

        return s;
    }
};