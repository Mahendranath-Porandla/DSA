class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n = nums.size();
        int i = 0;
        int j = 0;

        unordered_set<int> sett;
        while (j < n) {
            if ((j - i) <= k) {
                if (sett.count(nums[j])) {
                    return true;
                }
                sett.insert(nums[j]);
            } else {
                if (sett.erase(nums[i]))
                    ;
                i++;
                if (sett.count(nums[j])) {
                    return true;
                }
                sett.insert(nums[j]);
            }
            j++;
        }
        return false;
        ;
    }
};