class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        
        int n = nums.size();
        const long long MOD = 1000000007;

        // Difference array
        vector<int> freq(n + 1, 0);

        // Count how many times each index is requested
        for (auto &req : requests) {
            int start = req[0];
            int end = req[1];

            freq[start]++;

            if (end + 1 < n)
                freq[end + 1]--;
        }

        // Convert difference array to actual frequencies
        for (int i = 1; i < n; i++) {
            freq[i] += freq[i - 1];
        }

        // Sort both
        sort(nums.begin(), nums.end());
        sort(freq.begin(), freq.begin() + n);

        long long ans = 0;

        // Largest number × largest frequency
        for (int i = 0; i < n; i++) {
            ans = (ans + (long long)nums[i] * freq[i]) % MOD;
        }

        return ans;
    }
};
