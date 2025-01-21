class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
         int i = 0;
        int j = 0;
        int n = s.size();
        map<char,int> mp;
        for(char &ch: p){
            mp[ch]++;
        }
        
        vector<int> res;
        int ws = p.size();
        while(j < n){
            mp[s[j]]--;
            if(j-i < ws -1){
                j++;
            }else{
                // code to check for equality
                bool flag = true;
                for(auto &it: mp){
                    if(it.second !=0){
                        flag = false;
                    }
                }
                if(flag)    res.push_back(i);
                j++;
                mp[s[i]]++;
                i++;
            }
        }
        return res;
    }
};