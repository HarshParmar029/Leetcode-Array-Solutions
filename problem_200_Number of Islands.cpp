class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j) {

        int m = grid.size();
        int n = grid[0].size();

        // Boundary check
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }

        // Agar water hai ya already visited hai
        if (grid[i][j] == '0') {
            return;
        }

        // Is land ko visited mark karo
        grid[i][j] = '0';

        // Up
        dfs(grid, i - 1, j);

        // Down
        dfs(grid, i + 1, j);

        // Left
        dfs(grid, i, j - 1);

        // Right
        dfs(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {

                    // New island found
                    count++;

                    // Puri island ko visit karo
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};
