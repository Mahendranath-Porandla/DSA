class Solution {
public:
    int maxConsecutiveAnswers(string str, int k) {
        // sliding window
        // Approach
        // case 1 - flip the 'F'
        int f = 0;
        int i = 0;
        int j = 0;
        int n = str.size();
        int res = 0;
        while (j < n) {
            if (str[j] == 'F') {
                f++;
            }
            if (f > k) {
                // undo one flip from left
                while (str[i] != 'F') {
                    i++;
                }
                i++;
                f--;
            }
            res = max(res, j - i + 1);
            j++;
        }
        // case 2 - flip the 'T'
        i = 0;
        j = 0;
        int t = 0;
        while (j < n) {
            if (str[j] == 'T') {
                t++;
            }
            if (t > k) {
                // undo one flip from left
                while (str[i] != 'T') {
                    i++;
                }
                i++;
                t--;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};