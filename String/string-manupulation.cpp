/*
class Solution{
    public:
    int removeConsecutiveSame(vector <string > v)
    {
         stack<string>st;
          for(int i=0;i<v.size();i++){
              if(st.empty()){
                  st.push(v[i]);
              }
               else if(st.top()==v[i]){
                   st.pop();
               }else{
                   st.push(v[i]);
               }

          }

           int ans = st.size();
           return ans;
    }
};
*/

