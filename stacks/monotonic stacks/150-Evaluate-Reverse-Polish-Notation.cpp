class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& ch : tokens) {
            // if(ch[0]-'0'>=0 && ch[0]-'0'<=9){
            //     // then it is a number, so push it
            //     int temp = ch[0]-'0';
            //     st.push(temp);
            // }
            if (isdigit(ch[0]) || (ch[0] == '-' && ch.size() > 1)) {
                int temp = stoi(ch);
                st.push(temp);
            } else {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if (ch == "+") {
                    st.push(a + b);
                } else if (ch == "-") {
                    st.push(a - b);
                } else if (ch == "*") {
                    st.push(a * b);
                } else {
                    st.push(a / b);
                }
            }
        }
        return st.top();
    }
};