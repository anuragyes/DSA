#include <istream>
#include <vector>
#include <unordered_map>
using namespace std;

int  numberOfSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> oddCount;  // Maps the count of odd numbers to how many times we've seen that count
    oddCount[0] = 1;  // Base case: 0 odd numbers can be seen initially with an empty subarray
    int count = 0, oddNumbers = 0;

    for (int num : nums) {
        // If the number is odd, increment the count of odd numbers
        if (num % 2 == 1) {
            oddNumbers++;
        }
        
        // If there are 'k' odd numbers in the current subarray, increase the count
        if (oddCount.find(oddNumbers - k) != oddCount.end()) {
            count += oddCount[oddNumbers - k];
             cout<<count<<endl;
        }

        // Store the current count of odd numbers in the hashmap
        oddCount[oddNumbers]++;
    }

    return count;
}

 int main(){
    vector<int>nums={1,1,2,1,1};
     int k = 3
    numberOfSubarrays(nums,k)
    
     return 0;
 }