class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
int n = mat.size();
        stack<int> s;
        
        // Step 1: Push all people onto the stack.
        for(int i = 0; i < n; i++) {
            s.push(i);
        }
        
        // Step 2: Determine the potential celebrity by comparing people.
        while(s.size() > 1) {
            int first = s.top(); s.pop();
            int second = s.top(); s.pop();
            
            // If first knows second, first cannot be a celebrity, but second might be.
            if(mat[first][second] == 1) {
                s.push(second);
            }
            // If first doesn't know second, second cannot be a celebrity, but first might be.
            else {
                s.push(first);
            }
        }
        
        // Step 3: Check if the last person remaining in the stack is a celebrity.
        int ans = s.top(); s.pop();
        
        // Step 4: Verify the potential celebrity.
        int row = 0, column = 0;
        for(int i = 0; i < n; i++) {
            row += mat[ans][i];  // Row check - celebrity shouldn't know anyone.
            column += mat[i][ans];  // Column check - everyone should know the celebrity.
        }
        
        // Celebrity condition: row should be 0 (knows no one), and column should be n-1 (everyone knows).
        return (row == 0 && column == n - 1) ? ans : -1;
    }
};