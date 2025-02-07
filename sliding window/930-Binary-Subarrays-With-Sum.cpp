class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int curr_sum = 0;
        int n = nums.size();
        int res = 0;
        int nz = 0;
        int j = 0, i = 0;


        while(j < n){
            curr_sum += nums[j];
            while(i < j && (curr_sum > k || nums[i] == 0)){
                if(nums[i] == 0){
                    nz++;
                } else{
                    nz = 0;
                }
                curr_sum -= nums[i];
                i++;
            }
            if(curr_sum == k){
                res = res + nz + 1;
            }
            j++;
        }

        
    return res;

    }
};