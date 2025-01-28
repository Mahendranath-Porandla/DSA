class Solution {
public:
    string reverseParentheses(string s) {
        // brute force
        vector<int> open;
        // vector<int> close;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                open.push_back(i);
            }else if(s[i] == ')'){
                int start = open.back();
                int end = i;
                reverse(s.begin()+start , s.begin()+end);
                open.pop_back();
            }
        }
        string res;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '(' && s[i] != ')'){
                res+=s[i];
            }
        }
        return res;
    }
};