class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        vector<int>gnr(n,-1);
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(!st.empty()){
                gnr[i]=st.top();
            }
            st.push(nums2[i]);
        }
        // alternatively make gnr as map and access it using the key - making it O(2N) - time 
        vector<int> res;
        for(int i = 0;i<nums1.size();i++){
            for(int j = 0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    res.push_back(gnr[j]);
                }
            }
        }
        
        return res;
    }
};