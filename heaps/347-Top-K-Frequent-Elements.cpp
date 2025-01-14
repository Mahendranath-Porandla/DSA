class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int,int> P;
        unordered_map<int,int> mp;
        for(int &it: nums){
            mp[it]++;
        }
        struct lambda{
            bool operator()(const P p1, const P p2){
                return p1.second<p2.second;
            }
        };
        priority_queue<P, vector<P>, lambda> pq;
        for(auto &it: mp){
            pq.push({it.first,it.second});
        }
        vector<int> res;
        while(k>0){
            P temp = pq.top();
            pq.pop();
            res.push_back(temp.first);
            k--;
        }
        return res;
    }
};