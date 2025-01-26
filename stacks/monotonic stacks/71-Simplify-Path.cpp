class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream str(path);
        string tk;
        while(getline(str,tk,'/')){
            if(tk=="." || tk==""){
                continue;
            }else if(tk == ".."){
                if(!st.empty())
                    st.pop();
            }else{
                st.push(tk);
            }
        }
        string res;
        while(!st.empty()){
            res = '/' +st.top()+res;
            st.pop();
        }
        if(res == ""){
            res +='/';
        }
        return res;
    }
};