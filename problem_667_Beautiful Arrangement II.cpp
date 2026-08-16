class Solution {
public:
    vector<int> constructArray(int n, int k) {
        
        vector<int> ans;

        int left = 1;
        int right = n;

        // Create exactly k different differences
        while (left <= right && k > 1) {
            
            if (k % 2 == 1) {
                ans.push_back(left);
                left++;
            }
            else {
                ans.push_back(right);
                right--;
            }

            k--;
        }

        // Add remaining numbers
        if (left <= right) {
            ans.push_back(left);

            for (int i = left + 1; i <= right; i++) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
