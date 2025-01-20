class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = nums.size()-1;
        int res = 0;
        while(l<r){
            res = max(nums[r]+nums[l],res);
            l++;
            r--;
        }
        return res;
    }
};