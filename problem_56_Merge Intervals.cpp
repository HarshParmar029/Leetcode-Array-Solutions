class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Step 1: Sort intervals
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // Step 2: Take first interval
        ans.push_back(intervals[0]);

        // Step 3: Check remaining intervals
        for (int i = 1; i < intervals.size(); i++) {

            // If intervals overlap
            if (intervals[i][0] <= ans.back()[1]) {

                // Merge them
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else {

                // No overlap
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
