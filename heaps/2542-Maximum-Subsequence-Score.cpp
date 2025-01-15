
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> vec(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            vec[i].first = nums1[i];
            vec[i].second = nums2[i];
        }
        sort(vec.begin(), vec.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second > b.second;
             });
        long long sum = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 0; i < k; i++) {
            sum += vec[i].first;
            pq.push(vec[i].first);
        }
        long long min_ele = vec[k - 1].second;

        long long res = min_ele * sum;
        for (int i = k; i < nums1.size(); i++) {
            sum -= pq.top();
            sum += vec[i].first;
            pq.pop();
            pq.push(vec[i].first);
            res = max(res, sum * vec[i].second);
        }
        return res;
    }
};