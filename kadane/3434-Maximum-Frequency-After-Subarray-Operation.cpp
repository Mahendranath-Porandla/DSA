class Solution {
public:
    int kadane(vector<int> nums, int k, int t){
        int res = INT_MIN;
        int curr = 0;
        for(int &it : nums){
            if(it == k){
                curr--;
            }
            if(it == t){
                curr++;
            }
            if(curr < 0){
                curr = 0;
            }
            res = max(res, curr);
        }
        return res;
    }
    int maxFrequency(vector<int>& nums, int k) {
        // modified kadane's algorithm
        unordered_map<int,int> mp;
        for(int &it : nums){
            mp[it]++;
        }
        int res = INT_MIN;
        for(auto &it : mp){
            res = max(res, kadane(nums, k, it.first));
        }
        return res + mp[k];
    }
};