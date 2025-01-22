class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // using sliding window
        // we can also use prefix sum for this question
        int i = 0;
        int n = nums.size();
        int j = 0;
        vector<int> arr(n, -1);
        long long curr_sum = 0;

        while (j < n) {

            curr_sum += nums[j];

            if ((j - i + 1) >= ((2 * k) + 1)) {

                arr[i + k] = curr_sum / ((2 * k) + 1);
                curr_sum -= nums[i];

                i++;
            }
            j++;
        }
        return arr;
    }
};