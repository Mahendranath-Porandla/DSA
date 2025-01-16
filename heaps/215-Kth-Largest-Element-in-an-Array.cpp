class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &ot: nums){
            pq.push(ot);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};