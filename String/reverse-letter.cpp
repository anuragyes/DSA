class Solution {
    public:
        string reverseOnlyLetters(string s) {
               int left = 0, right = s.size() - 1;
    
        while (left < right) {
            // Move left pointer to the next letter
            if (!isalpha(s[left])) {
                left++;
                continue;
            }
            
            // Move right pointer to the previous letter
            if (!isalpha(s[right])) {
                right--;
                continue;
            }
    
            // Swap the letters at left and right
            swap(s[left], s[right]);
    
            // Move both pointers inward
            left++;
            right--;
        }
    
        return s;
        }
    };



    /*Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.

 

Example 1:

Input: s = "ab-cd"
Output: "dc-ba"
Example 2:

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 */