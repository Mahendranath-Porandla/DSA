class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        // sliding window
        // Approach
        // case 1 - flip the '0'
        int f = 0;
        int i = 0;
        int j = 0;
        int n = arr.size();
        int res = 0;
        while (j < n) {
            if (arr[j] == 0) {
                f++;
            }
            if (f > k) {
                // undo one flip from left
                while (arr[i] != 0) {
                    i++;
                }
                i++;
                f--;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};