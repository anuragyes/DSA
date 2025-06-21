// question 
/*
Given two numbers as strings s1 and s2. Calculate their Product.
Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers. You don't need to specify '+' sign in the begining of positive numbers.
*/




#include <bits/stdc++.h>
using namespace std;        

class Solution {
    public:
      /*You are required to complete below function */
      string multiplyStrings(string& s1, string& s2) {
          
          // Step 1: Handle sign
      bool isNegative = false;
      if (s1[0] == '-') {
          isNegative = !isNegative;
          s1 = s1.substr(1);
      }
      if (s2[0] == '-') {
          isNegative = !isNegative;
          s2 = s2.substr(1);
       
      }
  
      // Step 2: Remove leading zeros
      while (s1.length() > 1 && s1[0] == '0') s1.erase(0, 1);
      while (s2.length() > 1 && s2[0] == '0') s2.erase(0, 1);
  
      // Step 3: If either is "0", return "0"
      if (s1 == "0" || s2 == "0") return "0";
  
      int n = s1.size();
      int m = s2.size();
      vector<int> result(n + m, 0);
  
      // Step 4: Perform manual multiplication
      for (int i = n - 1; i >= 0; --i) {
          for (int j = m - 1; j >= 0; --j) {
              int digit1 = s1[i] - '0';
              int digit2 = s2[j] - '0';
              int pos1 = i + j;
              int pos2 = i + j + 1;
  
              int mul = digit1 * digit2 + result[pos2];
              result[pos2] = mul % 10;
              result[pos1] += mul / 10;
          }
      }
  
      // Step 5: Convert result to string
      string product = "";
      bool leadingZero = true;
      for (int num : result) {
          if (num == 0 && leadingZero) continue;
          leadingZero = false;
          product += (num + '0');
      }
  
      // Step 6: Add negative sign if needed
      if (isNegative) product = '-' + product;
  
      return product;
          // Your code here
          //   base case or edge case 
           
          //   brute force + using stl so its not acceptable 
          //   int num1 = stoi(s1);
          //     int num2 = stoi(s2);
          //      if(num1==0 || num2==0)  return "0";
               
          //      int ans = num1*num2;
               
          //      return to_string(ans);
              
              
      }
  };
  

   // C++ program to demonstrate functioning of substr()
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Take any string
    string s1 = "Geeks";

    // Copy two characters of s1 (starting
    // from index 3)
    string r = s1.substr(1);

    // prints the result
    cout << "String is: " << r;

    return 0;
}
