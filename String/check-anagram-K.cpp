#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    bool areKAnagrams(string str1, string str2, int k)
    {
        // Check if lengths are the same
        if (str1.length() != str2.length())
            return false;

        unordered_map<char, int> charCount;

        // Count characters in str1
        for (char ch : str1)
        {
            charCount[ch]++;
        }

        // Decrease the count based on characters in str2
        for (char ch : str2)
        {
            if (charCount.find(ch) != charCount.end())
            {
                charCount[ch]--;
            }
        }

        // Count how many characters are different
        int count = 0;
        for (const auto &entry : charCount)
        {
            if (entry.second > 0)
            {
                count += entry.second; // Sum up excess characters
            }
        }

        // Check if the number of differing characters is less than or equal to k
        return count <= k;
    }
};

Given two strings of lowercase alphabets and a value K, your task is to complete the given function which tells if two strings are K - anagrams of each other or not .

                                                                                                                                                                     Two strings are called K -
                                                                                                                                                                     anagrams if both of the below conditions are true .1. Both have same number of characters .2. Two strings can become anagram by changing at most K characters in a string.

                                                                                                                                                                     Example: