class Solution {
public:
    int solve(string s, char a, char b, int mul1, int mul2){
        stack<char> st;
        int n = s.size();
        for(char &ch : s){
            if(!st.empty() && st.top() == a && ch == b){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        string res;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        int ans = 0;
        ans = (s.size()-res.size())/2;
        ans *= mul1;
        st = stack<char>();
        for(char &ch : res){
            if(!st.empty() && st.top() == b && ch == a){
                st.pop();
            }else{
                st.push(ch);
            }
        }

        ans += ((res.size() - st.size())/2)*mul2;
        
        return ans;
        
    }
    int maximumGain(string s, int x, int y) {
        if(x>y) return solve(s, 'a', 'b', x, y);
        else return solve(s, 'b', 'a', y, x);
    }
};