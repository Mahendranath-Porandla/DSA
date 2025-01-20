class Solution {
public:
    int maxWidthRamp(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre_comp(n);
        int mx = arr[n-1];
        for(int i = n-1 ;i>=0 ;i--){
            mx=max(arr[i],mx);
            pre_comp[i]=mx;
        }
        int i=0,j=0;
        int res = 0;
        while(j<n){
            if(i<j && arr[i]> pre_comp[j]){
                i++;
                continue;
            }
            res = max(res, j-i);
            j++;
        }
        return res;
    }
};