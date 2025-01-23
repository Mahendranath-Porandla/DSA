class Solution {
public:
    char fun(char ch) {
        if (ch == ')')
            return '(';
        if (ch == '}')
            return '{';
        if (ch == ']')
            return '[';
        return ' ';
    }
    bool isValid(string s) {
        stack<int> st;
        for (char& ch : s) {
            if (!st.empty() && st.top() == fun(ch)) {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};