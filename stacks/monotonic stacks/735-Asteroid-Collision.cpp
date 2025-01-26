class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        // using monotonic stack
        stack<int> st;
        vector<int> res;
        for (int& it : arr) {
            bool blast = false; // will only keep track of current asteroid
            while(!st.empty() && st.top()>0 && it<0 ){
                if(abs(it) == abs(st.top())){
                    st.pop();
                    blast = true;
                    break;
                }else if(abs(it) < abs(st.top())){
                    blast = true; // current asteroid destroyed
                    // but top() not destroyed
                    break;
                }
                else{
                    st.pop();
                    // top() destroyed
                }
            }
            if(!blast){
                st.push(it);
            }
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};