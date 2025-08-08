#include <bits/stdc++.h>
#include <string>

string findShortestPalindrome(string &str)
{
    //  string reverse
    string rev = str;

    reverse(rev.begin(), rev.end());

    string combined = str + '#' + rev;

    int n = combined.size();
    vector<int> lps(n, 0);

    for (int i = 1; i < n; i++)
    {
        int length = lps[i - 1];
        while (length > 0 && combined[i] != combined[length])
        {
            length = lps[length - 1];
        }

        if (combined[i] == combined[length])
        {
            length++;
        }
        lps[i] = length;
    }

    int Palindrome = lps[n - 1];

    string add = str.substr(Palindrome);
    reverse(add.begin(), add.end());
    return add + str;
}

You are given a string ‘STR’.Your task is to find the shortest palindrome that can be formed by adding characters in front of ‘STR’.

    For example : You are given ‘STR’ = “aabcd”.Then our answer will be “dcbaabcd”.We can form a palindrome by adding ‘d’, ‘c’,
                                and ‘b’ in front of ‘STR’.