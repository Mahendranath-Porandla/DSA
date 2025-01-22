class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // sliding window
        // Approach :
        // Alternatively find the largest window containing only one zero
        // answer is that window minus one
        int i = 0;
        int n = nums.size();
        int j = 0;
        int res = 0;
        int nz = 0;
        while (j < n) {
            if (nums[j] == 0) {
                nz++;
            }
            while (nz >= 2) {
                if (nums[i] == 0) {
                    nz--;
                }
                i++;
            }
            res = max(j - i + 1, res);
            j++;
        }
        return res - 1;
    }
};