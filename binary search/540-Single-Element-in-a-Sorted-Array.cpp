class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        /*
            The Approaches here are
            - using maps - O(logn), O(n)
            - using xor - O(n), O(1)
            - using brute force - O(n), O(1)

            but we are looking for an approach with O(log n) time and O(1)
           space.

            - Since we are given a sorted array we use Binary Search

            -> Assume you are the mid
            -> now we assume two cases where and a boolean variable - isEven
            -> isEven - indicates whether the # of elements to the right of mid
           is even or odd case (i) - arr[mid]==arr[mid+1] if(isEven){
                    // Then the single element in to the right side
                }else{
                    // Then the single element in to the left side
                }

            case (ii) - arr[mid]!=arr[mid+1]
                if(isEven){
                    // Then the single element in to the left side
                }else{
                    // Then the single element in to the right side
                }

            return arr[left] or arr[right]
        */

        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            bool isEven = false;
            if ((right - mid) % 2 == 0) {
                isEven = true;
            }
            if (arr[mid] == arr[mid + 1]) {
                if (isEven) {
                    left = mid + 2;
                } else {
                    right = mid - 1;
                }
            } else {
                if (isEven) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
        }
        return arr[right];
    }
};