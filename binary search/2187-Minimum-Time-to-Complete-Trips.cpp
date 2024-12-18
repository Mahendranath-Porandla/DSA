class Solution {
public:

    bool check(vector<int> & arr, long long mid, int totalTrips){
        long long tp = 0;
        for(auto &it: arr){
            tp += mid/it;
            if(tp >= totalTrips){
                return true;
            }
        }
        return tp >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        /* 
            Lets see how brute force approach works here
            -- run a loop on time line (time 1 to something (infinity))
        */

        /* 
            Why Binary Search
            Now we do the same same thing we did in brute force approach but we follow binary search priciples , i.e.,
            --> if with mid(time) we are able to make totalTrips then ofcourse if are going to make totalTrips after mid(time)
            --> So we go left and if not we go right and at last we end up at our required answer

            --> now we loop at left and right
            left = 1 (obvious)
            right = min_time * totalTrips
        */

        // Edge case
        if(time.size() == 1){
            return (long long)time[0]*totalTrips;
        }
        long long left = 1;
        long long right = (long long)*min_element(time.begin(),time.end()) * totalTrips;
        long long ans = right;

        while(left <= right){

            long long mid = left + (right - left)/2;

            if(check(time , mid, totalTrips)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return ans;
    }
};