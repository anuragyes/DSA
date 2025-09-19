

// Recursive function to generate special strings
void generateSpecialStrings(vector<string>& A, int index, string current, vector<string>& result) {
    int N = A.size();
    
    // Base case: if we've picked characters for all positions
    if (index == N) {
        result.push_back(current);
        return;
    }
    
    // Try each character from A[index]
    for (char ch : A[index]) {
        generateSpecialStrings(A, index + 1, current + ch, result);
    }
}


void backtrack(vector<string>& A, int index, string& current, vector<string>& result) {
    int N = A.size();
    
    // Base case: formed a special string of length N
    if (index == N) {
        result.push_back(current);
        return;
    }
    
    // Try each character from the i-th string
    for (char ch : A[index]) {
        current.push_back(ch);          // Choose
        backtrack(A, index + 1, current, result); // Explore
        current.pop_back();             // Undo / Backtrack
    }
}



vector<string> Solution::specialStrings(vector<string> &arr) {
    
      vector<string> result;
    // generateSpecialStrings(arr, 0, "", result);
     string current = "";
      backtrack(arr, 0, current, result);
    
    // Sort the result lexicographically
    sort(result.begin(), result.end());
    return result;
}
