class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        typedef pair<int, pair<int, int>> P;
        priority_queue<P> pq;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> res;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                int sum = nums1[i] + nums2[j];
                if (pq.size() < k) {
                    pq.push({sum, {i, j}});
                } else if (pq.top().first > sum) {
                    pq.pop();
                    pq.push({sum, {i, j}});
                } else {
                    break;
                }
            }
        }
        while (!pq.empty()) {
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            res.push_back({nums1[i], nums2[j]});
            pq.pop();
        }
        return res;
    }
};