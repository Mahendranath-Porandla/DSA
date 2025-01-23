class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char &ch: s){
            if(!st.empty() && st.top() == ch){
                st.pop();
                continue;
            }
            st.push(ch);
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