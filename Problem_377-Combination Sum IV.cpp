class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        vector<long long> dp(target + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= target; i++) {

            for (int num : nums) {

                if (num <= i) {

                    dp[i] += dp[i - num];

                    // Prevent overflow
                    if (dp[i] > INT_MAX) {
                        dp[i] = INT_MAX;
                    }
                }
            }
        }

        return (int)dp[target];
    }
};
