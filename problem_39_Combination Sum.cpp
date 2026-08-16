class Solution {
public:

    vector<vector<int>> answer;

    void solve(vector<int>& candidates, int target,
               int index, vector<int>& current) {

        // Target complete ho gaya
        if (target == 0) {
            answer.push_back(current);
            return;
        }

        // Target negative ho gaya
        if (target < 0) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Current number choose karo
            current.push_back(candidates[i]);

            // Same number dobara use kar sakte hain
            solve(candidates, target - candidates[i],
                  i, current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                        int target) {

        vector<int> current;

        solve(candidates, target, 0, current);

        return answer;
    }
};
