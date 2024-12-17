class Solution {
public:
    /*
        The logic is here to find the pivot element index

        pivot element index = the mimimum element in the rotated sorted array, this the starting index.

        Now perform binary search on left side and right side of the pivot element
        
    */

    int findPivot(vector<int> nums, int target){
        int start=0;
        int end=nums.size()-1;
        while(start<end){
            int mid=start+(end-start)/2;
            if(nums[mid]>nums[end]){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        return end;
    }
    int BS(vector<int>& nums, int low, int high,int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                high=mid-1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                return mid;
                break;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot=findPivot(nums,target);
        if(nums[pivot]==target){
            return pivot;
        }
        int leftS=BS(nums,0,pivot-1,target);
        int rightS=BS(nums,pivot+1,nums.size()-1,target);
        if(leftS!=-1){
            return leftS;
        }else if(rightS!=-1){
            return rightS;
        }else{
            return -1;
        }
    }
};