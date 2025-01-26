class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int res = 0;
        unordered_map<int,int> mp(n);
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]>k){
                // pull the left one forward until we meet the condition
                while(mp[nums[j]]>k){
                    mp[nums[i]]--;
                    i++;
                }
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};