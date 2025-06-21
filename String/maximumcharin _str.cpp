/*

class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
            int arr[26]={0};
             for(int i =0;i<str.length();i++){
                  char ch = str[i];
                  int number = 0 ;
                   if(ch >= 'a' && ch <='z'){
                         number = ch-'a';
                   }else{
                        // upper case 
                         number = ch -'A';
                       
                   }
                    arr[number]++;
             }
              int maxi = 0 , ans = 0;
               for(int i =0;i<26;i++){
                    if(maxi<arr[i]){
                        ans = i ;
                        maxi = arr[i];
                    }
               }
                char finalans = 'a'+ans;
                return finalans;
            
    }

};
*/