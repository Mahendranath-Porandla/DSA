class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        /*
        Not an easy problem when we want to solve it using binary search
        Brute Force Approach - using while loop - O(n)
        */

        // BF

        int i = 0;
        int n = arr.size();
        int num=1;
        while(i<n && k>0){
            if(num==arr[i]){
                i++;
            }else{
                k--;
            }
            num++;
        }
        
        // The above loop will suffice for test cases where the array contains missing numbers and won't suffice for -> arr = [1,2,3,4], k = 2 , here after this loop k will still be 2, and now we have to exhaust that k

        while(k--){
            num++;
        }
        return num-1;
    }
};