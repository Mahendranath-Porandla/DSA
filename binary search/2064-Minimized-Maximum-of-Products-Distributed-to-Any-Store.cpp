class Solution {
public:
    bool isValid(vector<int>& arr, int n, int mid, int k) {
        for (int i = 0; i < n; i++) {
            k -= (arr[i] / mid) + (arr[i] % mid != 0 ? 1 : 0);
        }
        return k >= 0;
    }
    int minimizedMaximum(int n, vector<int>& arr) {
        // NOTE THIS : minimize the maximum
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int sz = arr.size();
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(arr, sz, mid, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};