class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        // Put all water cells into queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions: up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // BFS
        while (!q.empty()) {
            
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                
                int nx = x + dx[k];
                int ny = y + dy[k];

                // Check boundary
                if (nx >= 0 && nx < m &&
                    ny >= 0 && ny < n &&
                    height[nx][ny] == -1) {
                    
                    height[nx][ny] = height[x][y] + 1;

                    q.push({nx, ny});
                }
            }
        }

        return height;
    }
};
