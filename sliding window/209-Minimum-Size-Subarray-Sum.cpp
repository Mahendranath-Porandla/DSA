class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int j = 0;
        int res = INT_MAX;
        int curr_sum = 0;
        while (j < n) {
            curr_sum += arr[j];
            while (curr_sum >= target) {
                res = min(res, j - i + 1);
                curr_sum -= arr[i];
                i++;
            }
            j++;
        }

        return (res == INT_MAX) ? 0 : res;
    }
};