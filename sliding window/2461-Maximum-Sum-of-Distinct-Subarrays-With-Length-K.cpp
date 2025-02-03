class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> sett;
        long long sum = 0;
        int n = nums.size();
        int i = 0, j = 0;
        long long res = 0;

        while (j < n) {
            while(sett.count(nums[j])){
                sum -= nums[i];
                sett.erase(nums[i]);
                i++;
            }
            sett.insert(nums[j]);
            sum += nums[j];
            if(j - i + 1 == k){
                res = max(sum, res);
                sum -= nums[i];
                sett.erase(nums[i]);
                i++;
            }
            j++;
        }

        return res;
    }
};
