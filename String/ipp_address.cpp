/*Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

 

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
*/

/*class Solution {
public:
    string defangIPaddr(string address) {
    string defanged = ""; // make empty string to store the values
    for (char c : address) { // make a loop 
        if (c == '.') {    // now at the tym we found . 
            defanged += "[.]";   // push [.] 
        } else {
            defanged += c; // if not found .  add rest of elemnts
        }
    }
    return defanged;
    }
};*/