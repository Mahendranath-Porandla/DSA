/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return \t     -1 if num is higher than the picked number
 *\t\t\t      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low=0;
        int high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            int val=guess(mid);
            if(val==0){
                return mid;
            }else if(val==1){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return 0;
    }
};