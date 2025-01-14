class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int &it: stones){
            pq.push(it);
        }
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x==y){
                continue;
            }else{
                x=x-y;
                pq.push(x);
            }
        }
        if(pq.empty()){
            return 0;
        }else{
            return pq.top();
        }
    }
};