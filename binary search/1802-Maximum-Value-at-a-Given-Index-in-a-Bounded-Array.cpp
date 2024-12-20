#define ll long long
class Solution {
public:
    ll solve(ll c, ll n) { return (c * n) - (c * (c + 1)) / 2; }
    int maxValue(int n, int index, int maxSum) {
        ll left = 1;
        ll right = maxSum;
        int ans = 0;
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            ll left_count = min((ll)index , mid - 1);
            ll left_sum = solve(left_count, mid);
            left_sum += max((ll)0, index - (mid - 1));

            ll right_count = min((ll)n - index - 1 , mid - 1);
            ll right_sum = solve(right_count, mid);
            right_sum += max((ll)0, n - index - 1 - (mid - 1));

            ll total_sum = left_sum + right_sum +mid;
            if (total_sum <= maxSum) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};