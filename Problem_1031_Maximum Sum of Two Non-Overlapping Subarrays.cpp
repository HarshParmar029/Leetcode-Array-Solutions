class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
        int n = nums.size();

        // Prefix Sum
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = 0;

        // Case 1:
        // firstLen subarray comes before secondLen subarray
        int maxFirst = 0;

        for (int i = firstLen; i + secondLen <= n; i++) {
            
            // Best firstLen subarray ending before i
            maxFirst = max(
                maxFirst,
                prefix[i] - prefix[i - firstLen]
            );

            // Current secondLen subarray
            int secondSum = prefix[i + secondLen] - prefix[i];

            ans = max(ans, maxFirst + secondSum);
        }

        // Case 2:
        // secondLen subarray comes before firstLen subarray
        int maxSecond = 0;

        for (int i = secondLen; i + firstLen <= n; i++) {
            
            // Best secondLen subarray ending before i
            maxSecond = max(
                maxSecond,
                prefix[i] - prefix[i - secondLen]
            );

            // Current firstLen subarray
            int firstSum = prefix[i + firstLen] - prefix[i];

            ans = max(ans, maxSecond + firstSum);
        }

        return ans;
    }
};
