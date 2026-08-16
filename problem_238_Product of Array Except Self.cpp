class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, 1);

        // Left side ka product
        int left = 1;

        for (int i = 0; i < n; i++) {
            ans[i] = left;
            left = left * nums[i];
        }

        // Right side ka product
        int right = 1;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] = ans[i] * right;
            right = right * nums[i];
        }

        return ans;
    }
};
