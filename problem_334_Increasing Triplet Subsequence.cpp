class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int first = INT_MAX;
        int second = INT_MAX;

        for (int num : nums) {
            
            // Smallest number
            if (num <= first) {
                first = num;
            }
            
            // Number greater than first
            else if (num <= second) {
                second = num;
            }
            
            // Number greater than both
            else {
                return true;
            }
        }

        return false;
    }
};
