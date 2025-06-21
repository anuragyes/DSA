

// class Solution{
// public:
//     bool isSafe(int newx, int newy, vector<vector<int>>& m, vector<vector<bool>>& visited, int n){
//         return (newx >= 0 && newx < n && newy >= 0 && newy < n && !visited[newx][newy] && m[newx][newy] == 1);
//     }

//     void solve(int x, int y, vector<vector<int>>& m, int n, vector<string>& ans, string path, vector<vector<bool>>& visited){
//         if(x == n - 1 && y == n - 1){
//             ans.push_back(path);
//             return;
//         }

//         // Down
//         if(isSafe(x + 1, y, m, visited, n)){
//             visited[x][y] = true;
//             solve(x + 1, y, m, n, ans, path + 'D', visited);
//             visited[x][y] = false;
//         }
//         // Left
//         if(isSafe(x, y - 1, m, visited, n)){
//             visited[x][y] = true;
//             solve(x, y - 1, m, n, ans, path + 'L', visited);
//             visited[x][y] = false;
//         }
//         // Right
//         if(isSafe(x, y + 1, m, visited, n)){
//             visited[x][y] = true;
//             solve(x, y + 1, m, n, ans, path + 'R', visited);
//             visited[x][y] = false;
//         }
//         // Up
//         if(isSafe(x - 1, y, m, visited, n)){
//             visited[x][y] = true;
//             solve(x - 1, y, m, n, ans, path + 'U', visited);
//             visited[x][y] = false;
//         }
//     }

//     vector<string> findPath(vector<vector<int>>& m, int n) {
//         vector<string> ans;
//         vector<vector<bool>> visited(n, vector<bool>(n, false));
//         if(m[0][0] == 0) return ans;
//         solve(0, 0, m, n, ans, "", visited);
//         return ans;
//     }
// };

#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getPermutations(int num) {
    // Convert the number to a vector of digits
    vector<int> digits;
    while (num > 0) {
        digits.push_back(num % 10);
        num /= 10;
    }

    // Reverse the vector to start with the correct order
    reverse(digits.begin(), digits.end());

    // Vector to store all permutations
    vector<int> permutations;

    // Generate permutations using next_permutation
    do {
        int permNum = 0;
        for (int digit : digits) {
            permNum = permNum * 10 + digit;
        }
        permutations.push_back(permNum);
    } while (next_permutation(digits.begin(), digits.end()));

    return permutations;
}

int main() {
    int num = 123;
    vector<int> perms = getPermutations(num);

    cout << "Permutations of " << num << ": " << endl;
    for (int perm : perms) {
        cout << perm << " ";
    }
    cout << endl;

    return 0;
}

// int main()
// {
//     // int arr[] = {1, 3, 6, 4, 3, 2, 1};
//     int arr[] = {4,3,2,1,0};
//     for (int i = 1; i < 7; i++)
//     {
//         if (arr[i - 1] < arr[i])
//             continue;
//         else
//             cout << arr[i-1];
//              break;
//     }
//     return 0;
// }
