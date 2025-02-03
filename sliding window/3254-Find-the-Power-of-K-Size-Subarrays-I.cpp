class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n-k+1, -1);
        int count = 1;
        for(int i = 1; i < k; i++){
            if(nums[i-1]+1 == nums[i]){
                count++;
            }else{
                count = 1;
            }
        }
        if(count == k){
            res[0] = nums[k-1];
        }
        int i = 1, j = k;
        while(j < n){
            if(nums[j-1]+1 == nums[j]){
                count++;
            }else{
                count=1;
            }
            if(count>=k){
                res[i] = nums[j];
            }
            i++;
            j++;
        }
        return res;
    }
};