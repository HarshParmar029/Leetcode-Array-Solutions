class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        // Sort according to ending point
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 1;
        long long arrowPosition = points[0][1];
        
        for (int i = 1; i < points.size(); i++) {
            
            // Current balloon is not burst by previous arrow
            if (points[i][0] > arrowPosition) {
                arrows++;
                arrowPosition = points[i][1];
            }
        }
        
        return arrows;
    }
};
