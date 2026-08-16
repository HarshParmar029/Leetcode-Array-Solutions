class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int maxWater = 0;

        while (left < right) {

            // Calculate width
            int width = right - left;

            // Take smaller height
            int h = min(height[left], height[right]);

            // Calculate area
            int area = width * h;

            // Update maximum
            maxWater = max(maxWater, area);

            // Move the smaller line
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxWater;
    }
};
