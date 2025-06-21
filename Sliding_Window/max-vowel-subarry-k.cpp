/*Maximum Number of Vowels in a Substring of Given Length*/
/*Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.*/
class Solution {
public:

//  apprch relase karenge or release wla vowel hua toh ans-- or add wala vowel hua toh ans++ 
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    // Function to find the maximum number of vowels in a substring of length k
    int maxVowels(string s, int k) {
        int maxVowelCount = 0;
        int currentVowelCount = 0;

        // Initialize by counting vowels in the first window of size k
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) {
                currentVowelCount++;
            }
        }
        maxVowelCount = currentVowelCount;

        // Sliding window over the string
        for (int i = k; i < s.size(); ++i) {
            // Remove the effect of the character that goes out of the window
            if (isVowel(s[i - k])) {
                currentVowelCount--;
            }
            // Add the effect of the new character entering the window
            if (isVowel(s[i])) {
                currentVowelCount++;
            }
            // Update the maximum vowel count
            maxVowelCount = max(maxVowelCount, currentVowelCount);
        }

        return maxVowelCount;
    }
};