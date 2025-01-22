class Solution {
public:
    int maxConsecutiveAnswers(string str, int k) {
        // sliding window
        // Approach
        int res = 0;

        unordered_map<char, int> mp;

        int i = 0;
        for (int j = 0; j < str.length(); j++) {
            mp[str[j]]++;
            while (min(mp['T'], mp['F']) > k) {
                mp[str[i]]--;
                i++;
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
};