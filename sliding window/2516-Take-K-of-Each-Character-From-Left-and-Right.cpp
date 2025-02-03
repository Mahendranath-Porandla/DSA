class Solution {
public:
    int takeCharacters(string s, int k) {
        // very interesting sliding window question
        int n = s.size();
        int i = 0;
        int j = 0;
        int res = 0;
        unordered_map<char,int> mp;
        for(char &ch : s){
            mp[ch]++;
        }
        if (mp['a'] < k || mp['b'] < k || mp['c'] < k) {
            return -1;
        }
        while(j<n){
            mp[s[j]]--;
            while(i<=j && (mp['a'] < k || mp['b'] < k || mp['c'] < k)){
                mp[s[i]]++;
                i++;
            }
            res = max(j-i+1, res);
            j++;
        }
        return (n-res);

    }
};