class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int can) {
        typedef int P;
        priority_queue<P, vector<P>, greater<>> p1;
        priority_queue<P, vector<P>, greater<>> p2;
        int n = costs.size();
        int i = 0;
        int j = n-1;
        long long res = 0;
        while(k--){
            while(p1.size()<can && i<=j){
                p1.push(costs[i]);
                i++;
            }
            while(p2.size()<can && j>=i){
                p2.push(costs[j]);
                j--;
            }
            long long min_p1 = p1.size()==0 ? INT_MAX:p1.top();
            long long min_p2 = p2.size()==0 ? INT_MAX:p2.top();
            if(min_p1<=min_p2){
                res += p1.top();
                p1.pop();
            }else{
                res += p2.top();
                p2.pop();
            }

        }
        return res;
        
        
    }
};