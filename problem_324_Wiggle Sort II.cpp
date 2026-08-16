class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        vector<int> temp = nums;
        
        sort(temp.begin(), temp.end());
        
        int n = nums.size();
        
        int left = (n + 1) / 2 - 1;
        int right = n - 1;
        
        // Even positions: 0, 2, 4...
        // Put smaller elements
        for (int i = 0; i < n; i += 2) {
            nums[i] = temp[left];
            left--;
        }
        
        // Odd positions: 1, 3, 5...
        // Put larger elements
        for (int i = 1; i < n; i += 2) {
            nums[i] = temp[right];
            right--;
        }
    }
};
