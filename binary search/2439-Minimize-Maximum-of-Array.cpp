class Solution {
public:
    bool check(vector<int> arr, int mid, int n){
        // use this or else it will result in Buffer overflow INT error
        vector<long long> temp(arr.begin(), arr.end());
        for(int i=0; i<n-1 ; i++){
            if(temp[i]>mid){
                return false;
            }
            long long buffer = mid - temp[i];
            temp[i]+=buffer;
            temp[i+1]= temp[i+1]-buffer;
        }
        return temp[n-1]<=mid;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(nums, mid, n)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};