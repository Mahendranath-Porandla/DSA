class Solution {
public:
    int maxArea(vector<int>& arr) {
        // optimal - two pointer(O(n))
        // can also be solve using stack(O(n))
        // Approach is : put l on left and r on right, we keep decreasing the width, now as we are decreasing the width we want to increase the res, so only way to do that is move the smallest pole between l, and r.
        int n = arr.size();
        int l = 0;
        int r = n-1;
        int res = 0;
        while(l<r){
            int diff = r - l;
            res = max(res, min(arr[r],arr[l]) * diff);
            if(arr[l] < arr[r]){
                l++;
            }else{
                r--;
            }
        }
        return res;
        
    }
};