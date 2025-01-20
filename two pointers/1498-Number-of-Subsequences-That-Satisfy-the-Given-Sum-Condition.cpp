class Solution {
public:
    int numSubseq(vector<int>& arr, int target) {
        int n = arr.size();
        int mod = (int)1e9+7;

        // pre comp powers of 2
        vector<int> power(n, 1);
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        sort(arr.begin(), arr.end());

        int l = 0, r = n - 1, res = 0;

        while (l <= r) {
            if (arr[l] + arr[r] <= target) {
                
                res = (res + power[r - l]) % mod;
                l++;
            } else {
                r--;
            }
        }

        return res % mod;
    }
};
