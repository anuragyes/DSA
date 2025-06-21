class Solution{
  public:
    int isdivisible7(string num){
              //complete the function here
        // Variable to store the current remainder
        int remainder = 0;
        
        // Iterate through each digit in the string
        for (char digit : num) {
            // Update remainder by adding the current digit and taking modulo 7
            remainder = (remainder * 10 + (digit - '0')) % 7;
        }
        if(remainder==0)
            return 1;
        else
            return 0;
    }
};