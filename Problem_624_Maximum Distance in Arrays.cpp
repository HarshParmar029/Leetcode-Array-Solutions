class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {

        int answer = 0;

        // Smallest value from the first array
        int minValue = arrays[0][0];

        // Largest value from the first array
        int maxValue = arrays[0].back();

        for (int i = 1; i < arrays.size(); i++) {

            // Distance using current array's largest value
            answer = max(answer, arrays[i].back() - minValue);

            // Distance using current array's smallest value
            answer = max(answer, maxValue - arrays[i][0]);

            // Update smallest and largest values
            minValue = min(minValue, arrays[i][0]);
            maxValue = max(maxValue, arrays[i].back());
        }

        return answer;
    }
};
