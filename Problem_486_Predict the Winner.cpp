class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n));

        // Base case:
        // Only one number is left
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        // Check different lengths
        for (int len = 2; len <= n; len++) {
            
            for (int i = 0; i + len - 1 < n; i++) {
                
                int j = i + len - 1;

                // Take left OR take right
                int takeLeft = nums[i] - dp[i + 1][j];
                int takeRight = nums[j] - dp[i][j - 1];

                dp[i][j] = max(takeLeft, takeRight);
            }
        }

        // If score difference >= 0,
        // Player 1 wins or ties
        return dp[0][n - 1] >= 0;
    }
};
