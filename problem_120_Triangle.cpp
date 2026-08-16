class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        // Start from second last row
        for (int i = triangle.size() - 2; i >= 0; i--) {

            // Traverse current row
            for (int j = 0; j < triangle[i].size(); j++) {

                // Add minimum of two adjacent numbers below
                triangle[i][j] += min(triangle[i + 1][j],
                                      triangle[i + 1][j + 1]);
            }
        }

        // Top element contains minimum path sum
        return triangle[0][0];
    }
};
