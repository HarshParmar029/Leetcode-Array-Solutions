class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        map<int, vector<int>> diagonals;
        
        // Store elements according to i + j
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                diagonals[i + j].push_back(nums[i][j]);
            }
        }
        
        vector<int> ans;
        
        // Traverse every diagonal
        for (auto &p : diagonals) {
            
            vector<int>& v = p.second;
            
            // Reverse because diagonal is needed bottom -> top
            reverse(v.begin(), v.end());
            
            for (int x : v) {
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};
