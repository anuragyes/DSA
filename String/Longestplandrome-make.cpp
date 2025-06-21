#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

// Function to expand around the center and check for palindrome
string expandAroundCenter(const string &s, int left, int right)
{
    while (left >= 0 && right < s.size() && s[left] == s[right])
    {
        left--;
        right++;
    }
    // Return the palindrome substring
    return s.substr(left + 1, right - left - 1);
}

// Function to find the longest palindrome in the given string
string solve1(string s)
{
    if (s.empty())
        return "";

    string longest = "";

    for (int i = 0; i < s.size(); i++)
    {
        // Odd-length palindrome
        string palindrome1 = expandAroundCenter(s, i, i);
        // Even-length palindrome
        string palindrome2 = expandAroundCenter(s, i, i + 1);

        // Update the longest palindrome if a longer one is found
        if (palindrome1.length() > longest.length())
        {
            longest = palindrome1;
        }
        if (palindrome2.length() > longest.length())
        {
            longest = palindrome2;
        }
    }
    return longest;
}

// Function to calculate the longest palindrome from two strings s and t
int longestPalindrome(string s, string t)
{
    unordered_map<char, int> maap;
    for (auto element : s)
    {
        maap[element]++;
    }
    int count = 0; // Start from 0 instead of 1 for proper counting.

    // Count how many characters in t exist in s
    for (auto ele : t)
    {
        if (maap.find(ele) != maap.end())
        {
            count++;
        }
    }

    // Check if there is at least one common character
    if (count == 0)
    {
        int res1 = solve1(s); // Get the longest palindrome from s
        int res2 = solve1(t); // Get the longest palindrome from t

        return max(res1.length(), res2.length()); // Return the length of the longest palindrome
    }
    else
    {
        // If there are common characters, return count
        return count;
    }
}

int main()
{
    string s = "aaaaa";
    string t = "b";
    count << longestPalindrome(s, t);
}
