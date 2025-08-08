#include <bits/stdc++.h>
using namespace std;

bool canPartition(int index, vector<int>& arr, vector<int>& subsetSum, int target, int K) {
    if(index == arr.size()) {
        for(int i = 0; i < K; ++i)
            if(subsetSum[i] != target)
                return false;
        return true;
    }

    for(int i = 0; i < K; ++i) {
        if(subsetSum[i] + arr[index] <= target) 
        {
            subsetSum[i] += arr[index];

            if(canPartition(index + 1, arr, subsetSum, target, K))
                return true;

            subsetSum[i] -= arr[index];
        }

        // Optimization: avoid duplicate subsets
        if(subsetSum[i] == 0) break;
    }

    return false;
}

bool splitArray(vector<int>& arr, int K) {
    int N = arr.size();
    if(K > N) return false;

    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if(totalSum % K != 0) return false;

    int target = totalSum / K;
    sort(arr.rbegin(), arr.rend()); // Start from largest to help pruning

    vector<int> subsetSum(K, 0);
    return canPartition(0, arr, subsetSum, target, K);
}
