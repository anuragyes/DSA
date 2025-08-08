class Solution {
  public:
    string encode(vector<string>& s) {
        //  step first 
        
        //  add length of the first string + # + string first
           string encoded = "";
        for (const string& str : s) {
            encoded += to_string(str.size()) + "#" + str;
        }
        return encoded;
        
    }

    vector<string> decode(string& s) {
        
      vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            // Find the delimiter (#)
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            result.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return result;
    }
};


Given an array of strings s[], you are required to create an algorithm in the encode() function that can convert the given strings into a single encoded string, which can be transmitted over the network and then decoded back into the original array of strings. The decoding will happen in the decode() function.

You need to implement two functions:
1. encode(): This takes an array of strings s[] and encodes it into a single string. 
2. decode(): This takes the encoded string as input and returns an array of strings containing the original array as given in the encode method.

Note: You are not allowed to use any inbuilt serialize method.  

Examples: