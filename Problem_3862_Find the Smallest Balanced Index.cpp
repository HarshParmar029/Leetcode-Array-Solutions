class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {

        int n = nums.size();

        long long LIMIT = 100000000000001LL;

        vector<long long> right(n + 1, 1);

        // Calculate product from right side
        for (int i = n - 1; i >= 0; i--) {

            if (nums[i] == 0) {
                right[i] = 0;
            }
            else if (right[i + 1] > LIMIT / nums[i]) {
                right[i] = LIMIT;
            }
            else {
                right[i] = right[i + 1] * nums[i];
            }
        }

        long long leftSum = 0;

        for (int i = 0; i < n; i++) {

            // Check left sum == right product
            if (leftSum == right[i + 1]) {
                return i;
            }

            // Add current element to left
            leftSum += nums[i];
        }

        return -1;
    }
};
