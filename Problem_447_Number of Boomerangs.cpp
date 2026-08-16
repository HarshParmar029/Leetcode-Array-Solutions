class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        int n = points.size();
        int answer = 0;

        for (int i = 0; i < n; i++) {

            unordered_map<long long, int> mp;

            for (int j = 0; j < n; j++) {

                if (i == j)
                    continue;

                long long x = points[i][0] - points[j][0];
                long long y = points[i][1] - points[j][1];

                long long distance = x * x + y * y;

                mp[distance]++;
            }

            // Count possible boomerangs
            for (auto it : mp) {

                int count = it.second;

                answer += count * (count - 1);
            }
        }

        return answer;
    }
};
