class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int number = 0;
        int sign = 1;
        int result = 0;
        for (char& ch : s) {
            if ((ch - '0') >= 0 && (ch - '0') <= 9) {
                // we found a number
                int temp = ch - '0';
                number = (10 * number) + temp;
            } else if (ch == '+') {
                result += (sign)*number;
                sign = 1;
                number = 0;

            } else if (ch == '-') {
                result += (sign)*number;
                sign = -1;
                number = 0;

            } else if (ch == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            } else if (ch == ')') {
                result += (sign)*number;
                number = 0;
                sign = 1;
                int stack_sign = st.top();
                st.pop();
                result = result * (stack_sign);
                int stack_val = st.top();
                st.pop();
                result += stack_val;
            }
        }
        result += (sign)*number;
        return result;
    }
};