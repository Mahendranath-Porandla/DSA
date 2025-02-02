class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int res = 0;
        for(char &ch : s){
            if(!st.empty() && st.top()=='b' && ch == 'a'){
                st.pop();
                res++;
            }else{
                st.push(ch);
            }
        }
        return res;

    }
};