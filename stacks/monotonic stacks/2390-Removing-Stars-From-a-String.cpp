class Solution {
public:
    string removeStars(string s) {
        stack<int> st;
        for(char &ch : s){
            if(ch == '*'){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        string str;
        while(!st.empty()){
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};