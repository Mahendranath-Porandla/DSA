class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int outlier = -1;
        int min_i = -1;
        int max_i = -1;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK)
                outlier = i;
            if (nums[i] == minK)
                min_i = i;
            if (nums[i] == maxK)
                max_i = i;
            long long temp = min(min_i, max_i) - outlier;
            ans += (temp <= 0) ? 0 : temp;
        }
        return ans;
    }
};