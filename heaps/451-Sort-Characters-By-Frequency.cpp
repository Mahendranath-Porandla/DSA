class Solution {
public:
    string frequencySort(string s) {
        typedef pair<char,int> P;
        unordered_map<char,int> mp;
        for(char &ch:s){
            mp[ch]++;
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
        string res;
        while(!pq.empty()){
            P temp = pq.top();
            pq.pop();
            res+=string(temp.second, temp.first);
        }
        return res;


    }
};