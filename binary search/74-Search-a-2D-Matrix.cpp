class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        // This appriach is O(n+m)
            int i = 0;
            int j = matrix[0].size() - 1;
            int r = matrix.size() - 1;
            int c = matrix[0].size();
            while(i<=r && j>=0){
                if(matrix[i][j]>target){
                    j--;
                }
                else if(matrix[i][j]<target){
                    i++;
                }else{
                    return true;
                }
            }
            return false;
        */

        // Now let us assume the 2d array as 1d array only while calulating the
        // start, end, and mid. But for comparing we need row_idx and col_idx,
        // So row_idx = mid/c & col_idx = mid%c where c is the # of cols
        int start = 0;
        int c = matrix[0].size();
        int end = matrix.size() * matrix[0].size() - 1;
        while (start <= end) {
            int mid = (start) + (end - start) / 2;
            if (matrix[mid / c][mid % c] < target) {
                start = mid + 1;
            } else if (matrix[mid / c][mid % c] > target) {
                end = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};