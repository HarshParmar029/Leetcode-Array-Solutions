class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
        const long long MOD = 1000000007;

        long long even = 1;
        long long odd = 0;
        long long ans = 0;

        int sum = 0;

        for (int x : arr) {
            
            sum += x;

            if (sum % 2 == 0) {
                // Current prefix is even.
                // Pair it with previous odd prefixes.
                ans = (ans + odd) % MOD;
                even++;
            }
            else {
                // Current prefix is odd.
                // Pair it with previous even prefixes.
                ans = (ans + even) % MOD;
                odd++;
            }
        }

        return ans;
    }
};
