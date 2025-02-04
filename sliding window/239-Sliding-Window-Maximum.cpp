class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        deque<int> deq;
        vector<int> res;
        while (i < n) {
            while(!deq.empty() && deq.front() <= i - k){
                deq.pop_front();
            }
            while(!deq.empty() && nums[deq.back()]< nums[i]){
                deq.pop_back();
            }
            deq.push_back(i);
            if(i >= k-1){
                res.push_back(nums[deq.front()]);
            }
            i++;
        }

        return res;
    }
};