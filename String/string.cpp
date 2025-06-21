#include <iostream>
#include <string>
using namespace std;
#include <unordered_map>
#include <unordered_set>


 int main(){
     char ch = 'a';
     cout<<ch - 'a'<<endl;
     return 0;
 }

// class Solution
// {
// public:
//     int numSpecialLetters(std::string word)
//     {
//         // To track positions of lowercase and uppercase letters
//         std::unordered_map<char, bool> seenLowercase;
//         std::unordered_map<char, bool> seenUppercase;
//         int specialCount = 0;

//         // Traverse the string once
//         for (char c : word)
//         {
//             if (std::islower(c))
//             {
//                 // Mark that we have seen the lowercase letter
//                 seenLowercase[c] = true;
//             }
//             else if (std::isupper(c))
//             {
//                 // Mark that we have seen the uppercase letter
//                 seenUppercase[c] = true;
//             }
//         }

//         // Now check for special letters
//         for (auto &entry : seenLowercase)
//         {
//             char c = entry.first;
//             // If both lowercase and uppercase occurrences are present
//             if (seenUppercase.find(c) != seenUppercase.end())
//             {
//                 // It is a special letter if no uppercase occurrences precede any lowercase occurrences
//                 specialCount++;
//             }
//         }

//         return specialCount;
//     }
// };

// int main()
// {
//     // Solution solution;
//     // std::string word = "aAaBbCc";
//     // std::cout << "Special letters count: " <<
//     //  solution.numSpecialLetters(word);
   

//     return 0;
// }
