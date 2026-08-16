class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            long long square = 1LL * nums[i] * nums[i];

            // First half gets negative sign
            if (i < n / 2) {
                ans -= square;
            }
            else {
                // Remaining elements get positive sign
                ans += square;
            }
        }

        return ans;
    }
};
