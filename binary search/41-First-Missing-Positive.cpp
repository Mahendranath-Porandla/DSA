class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==1){
            if(nums[0]==1){
                return 2;
            }
            return 1;
        }
        unordered_set<int> sett;
        int mx=INT_MIN;
        for(int i : nums){
            if(i>=0){
                sett.insert(i);
                mx=max(mx,i);
            }
        }
        if(mx==INT_MIN){
            return 1;
        }
        long long min_p=(long long)mx+1;
        for(int i=1;i<mx;i++){
            if(sett.count(i)==0){
                min_p=i;
                break;
                sett.insert(i);
            }
        }
        return (int)min_p;
        
    }
};