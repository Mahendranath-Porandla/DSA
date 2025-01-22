class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int res = 0;
        int curr_res = 0;
        unordered_set<char> sett;
        sett.insert('a');
        sett.insert('e');
        sett.insert('i');
        sett.insert('o');
        sett.insert('u');
        while(j<n){
            if(sett.count(s[j])){
                curr_res++;
            }
            if((j-i+1)>k){
                if(sett.count(s[i])){
                    curr_res--;
                }
                i++;
            }
            j++;
            res = max(res, curr_res);
        }
        return res;
    }
};