class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int tz = target.size();
        int i = 1, j = 0;
        vector<string> res;
        while(j < tz){
            if(target[j] == i){
                res.push_back("Push");
                i++;
                j++;
            }else{
                res.push_back("Push");
                res.push_back("Pop");
                i++;
            }
        }
        return res;
    }
};