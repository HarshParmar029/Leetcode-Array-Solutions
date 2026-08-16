class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int maxNum = 0;
        
        for (int x : nums) {
            maxNum = max(maxNum, x);
        }
        
        // points[i] = total points we get by taking number i
        vector<int> points(maxNum + 1, 0);
        
        for (int x : nums) {
            points[x] += x;
        }
        
        // House Robber DP
        int prev2 = 0;
        int prev1 = 0;
        
        for (int i = 1; i <= maxNum; i++) {
            
            int take = prev2 + points[i];
            int skip = prev1;
            
            int current = max(take, skip);
            
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};
