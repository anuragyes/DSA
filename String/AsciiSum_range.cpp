class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
      
         unordered_map<char, pair<int, int>>index;
        
         vector<int>ans;
         
          for(int i=0;i<s.size();i++){
               if(index.find(s[i])==index.end()){
                   index[s[i]].first=i;
               }
               index[s[i]].second = i;
          }
          
          
            // step second 
            
             for(auto &value:index){
                 
                 int first = value.second.first;
                 int second = value.second.second;
                 
                  if(first!=second){
                       int sum =0;
                      for(int i=first+1;i<second;i++){
                        //   convert into ascii value 
                            sum = sum + (int)s[i];
                      }
                      
                        if(sum>0)  ans.push_back(sum);
                  }
             }
             
              return ans;
    }
};


Given a string s consisting of lowercase English letters, for every character whose first and last occurrences are at different positions, calculate the sum of ASCII values of characters strictly between its first and last occurrence.
Return all such non-zero sums (order does not matter).



 unordered_map<int,int>maap;

  for(auto element:arr){
    maap[element] = i;
  }

   for(auto element:arr){
    maap[element]++;
  }