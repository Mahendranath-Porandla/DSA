class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // using monotonic stack
        // we find two arrays
        // snl - smallest number to the left - but only stores indexes
        // snr - smallest number to the right - but only stores indexes
        typedef unsigned long long ll;
        int mod = (int)1e9+7;
        stack<int> st;
        int n = arr.size();
        vector<int> snl(n, -1);
        vector<int> snr(n, n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                snl[i] = st.top();
            }
            st.push(i);
        }
        // clearing the stack to use again
        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                snr[i] = st.top();
            }
            st.push(i);
        }
      ll res = 0;
        for (int i = 0; i < n; i++) {
            ll left_dist = i - snl[i];
            ll right_dist = snr[i] - i;
            ll temp = ((left_dist * right_dist) % mod * arr[i] % mod) % mod;
            res = (res + temp) % mod;
        }
        return (int)res;
    }
};