
class Solution {
public:
    bool check(vector<int>& arr, int mid, int h) {
        int curr_h = 0;
        for (auto& it : arr) {
            if (it % mid == 0)
                curr_h += (it / mid);
            else
                curr_h += (it / mid) + 1;
            if (curr_h > h) {
                return false;
            }
        }
        return curr_h <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(piles, mid, h)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};