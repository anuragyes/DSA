#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Kadane's algorithm to find max subarray sum
int kadane(const vector<int>& arr) {
    int maxSum = INT_MIN, currentSum = 0;
    for (int val : arr) {
        currentSum = max(val, currentSum + val);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int maximumSumRectangle(vector<vector<int>>& ARR, int N, int M) {
    int maxSum = INT_MIN;

    // Left and right boundaries of the rectangle
    for (int left = 0; left < M; ++left) {
        vector<int> temp(N, 0); // Temporary array for storing row sums

        for (int right = left; right < M; ++right) {
            // Add values from current column to temp
            for (int row = 0; row < N; ++row) {
                temp[row] += ARR[row][right];
            }

            // Find the max sum subarray in temp using Kadane's algorithm
            int currentMax = kadane(temp);
            maxSum = max(maxSum, currentMax);
        }
    }

    return maxSum;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> ARR(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> ARR[i][j];

    int result = maximumSumRectangle(ARR, N, M);
    cout << "Maximum Sum Rectangle: " << result << endl;

    return 0;
}
