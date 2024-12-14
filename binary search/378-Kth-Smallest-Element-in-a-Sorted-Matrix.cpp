class Solution {
public:
    int check(vector<vector<int>>& arr, int mid){
        int r=0;
        int n=arr.size();
        int count=0;
        int c=n-1;
        while(r<n && c>=0){
            if(arr[r][c]<=mid){
                count+=(c+1);
                r++;
            }else{
                c--;
            }   
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& arr, int k) {
        int n=arr.size();
        int low=arr[0][0];
        int high=arr[n-1][n-1];

        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(arr,mid)<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }

        }
        return low;
    }
};