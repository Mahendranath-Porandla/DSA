class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        typedef pair<int,int> P;
        priority_queue<P, vector<P>, greater<>> pq;  
        sort(tasks.begin(),tasks.end());
        vector<int> res;
        int idx = 0;
        long long time =0;
        while(idx<n || !pq.empty()){
            if(pq.empty() && tasks[idx][0]>time){
                time = tasks[idx][0];
            }
            while(idx<n && tasks[idx][0]<=time){
                pq.push({tasks[idx][1],tasks[idx][2]});
                idx++;
            }
            P temp=pq.top();
            pq.pop();
            time+=temp.first;
            res.push_back(temp.second);
        }
        return res;
        
    }
};