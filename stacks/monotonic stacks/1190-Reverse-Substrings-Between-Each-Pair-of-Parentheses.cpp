class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> open;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(') {
                open.push(i);
            } else if (ch == ')') {
                int temp = open.top();
                open.pop();
                mp[temp] = i;
                mp[i] = temp;
            }
        }
        int flag = 1;
        string res;
        for (int i = 0; i < n; i += flag) {
            char ch = s[i];
            if (ch == '(' || ch == ')') {
                i = mp[i];
                flag = -1 * flag;
            } else {
                res += ch;
            }
        }
        return res;
    }
};