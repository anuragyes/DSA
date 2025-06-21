
//   steps to solve the problem 
//  1. concatinate all the char 
// 2. second step to check concatinate string is plandrome 



/*



bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
class Solution {
  public:
    bool compute(Node* head) {
        
        
         if (head == nullptr) {
        return true;
    }
    
    // Traverse the linked list and concatenate all strings
    string combinedString = "";
    Node* current = head;
    while (current != nullptr) {
        combinedString += current->data;
        current = current->next;
    }
    
    // Check if the combined string is palindrome
    return isPalindrome(combinedString);

    }
};*/