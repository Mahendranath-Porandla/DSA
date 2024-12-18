#define ll long long
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());

        long long spells_size = spells.size();
        vector<int> ans;
        long long max_ele = potions[potions.size() - 1];
        for (int i = 0; i < spells_size; i++) {
            long long left = 0;
            long long right = potions.size()-1;
            int idx = potions.size();
            while (left <= right) {
                long long mid = left + (right - left) / 2;
                bool sucess_check = false;
                if ( (long long) spells[i] * potions[mid] >= success) {
                    sucess_check = true;
                }
                if (sucess_check) {
                    idx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            ans.push_back(potions.size() - idx);
        }
        return ans;
    }
};