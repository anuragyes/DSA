/*class Solution {
public:
    string removeDuplicates(string s) {

        // initialising an empty string
        string ans = "";
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char currentCharacter = s[i];
            if (ans.empty()) {
                // agar string  empty hai
                // toh soocho mat elementpush kro
                ans.push_back(currentCharacter);
            }
            // ab charcter push krne se phele rightmost se compare
            // rightmost kaise nikale -->ans.back()
            // agar same hai toh delete krna hoga
            else if (currentCharacter == ans.back()) {
                ans.pop_back();

            } else if (currentCharacter != ans.back()) {
                ans.push_back(currentCharacter);
            }
        }
        return ans;
        /*
    //    using stack
        stack<char> st;
        for(char ch : s)
        {
            if(st.empty())
            {
                st.push(ch);
            }
            else
            {
                if(st.top() == ch)
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        */
    }
};*/