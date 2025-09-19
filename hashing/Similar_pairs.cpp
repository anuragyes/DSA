// int Solution::solve(vector<int> &arr, int B) {
//     int count = 0;
//     unordered_map<int, vector<int>> maap;

//     // Store indices of each number
//     for (int i = 0; i < arr.size(); i++) {
//         maap[arr[i]].push_back(i);
//     }

//     // Check pairs
//     for (auto &p : maap) {
//         auto &indices = p.second;
//         for (int i = 0; i < indices.size(); i++) {
//             for (int j = i + 1; j < indices.size(); j++) {
//                 if (indices[j] - indices[i] <= B) {
//                     count++;
//                 }
//             }
//         }
//     }

//     return count;
// }

int Solution::solve(vector<int> &A, int B) {
    const int MOD = 1e9 + 7;
    long long count = 0;
    unordered_map<int, int> freq;

    for (int j = 0; j < A.size(); j++) {
        // Add pairs ending at j
        if (freq.find(A[j]) != freq.end()) {
            count = (count + freq[A[j]]) % MOD;
        }

        // Add current element to window
        freq[A[j]]++;

        // Remove element that is out of window
        if (j - B >= 0) {
            freq[A[j - B]]--;
            if (freq[A[j - B]] == 0) {
                freq.erase(A[j - B]);
            }
        }
    }

    return (int)(count % MOD);
}


/*Given an integer array A of size N, you need to find the count of pairs  (i, j) such that:

i < j
j - i <= B
A[i] == A[j]
Return the count of such pairs modulo 109 + 7.



Problem Constraints
2 <= |A| <= 105

1 <= A[i] <= 109

1 <= B <= 105



Input Format
First argument is an integer array A.

Second argument is an integer B.



Output Format
Return the count of such pairs that's satisfies all the properties mentioned above in the statement, modulo 109 + 7.



Example Input
Input 1:

 A = [1, 2, 1, 3, 1, 4]
 B = 2
Input 2:

 A = [12, 11, 8, 1]
 B = 14


Example Output
Output 1:

 2
Output 2:

 0


Example Explanation
Explanation 1:

 First pair is (0, 2) as A[0] = A[2] and (2 - 0) <= 2
 Second pair is (2, 4)
Explanation 2:

 No such pair possible as all elements are distinct.
*/