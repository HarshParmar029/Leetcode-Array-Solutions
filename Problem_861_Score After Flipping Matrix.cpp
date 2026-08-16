class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        // Check every column
        for (int j = 0; j < n; j++) {

            int ones = 0;

            // Count effective 1s in this column
            for (int i = 0; i < m; i++) {

                // If first element of row is 0,
                // that row would be flipped.
                int value = grid[i][j];

                if (grid[i][0] == 0) {
                    value = 1 - value;
                }

                if (value == 1) {
                    ones++;
                }
            }

            // We can flip the column if it gives more 1s
            ones = max(ones, m - ones);

            // Contribution of this column
            ans += ones * (1 << (n - j - 1));
        }

        return ans;
    }
};
