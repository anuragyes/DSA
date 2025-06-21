

class Solution {
public:
    bool possible(int arr[], int n, int k, int mid) {
        int painter = 1;
        int color = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] + color <= mid) {
                color += arr[i];
            } else {
                painter++;
                if (painter > k || arr[i] > mid) {
                    return false;
                }
                color = arr[i];
            }
        }
        return true;
    }
    
    long long minTime(int arr[], int n, int k) {
        int start = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        int end = sum;
        long long ans = -1;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            if (possible(arr, n, k, mid)) {
                end = mid - 1;
                ans = mid;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
