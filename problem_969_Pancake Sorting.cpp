class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        
        vector<int> ans;
        int n = arr.size();

        // Largest element ko one-by-one correct position par rakhenge
        for (int curr = n; curr > 1; curr--) {

            // curr ko find karo
            int pos = 0;

            for (int i = 0; i < curr; i++) {
                if (arr[i] == curr) {
                    pos = i;
                    break;
                }
            }

            // Agar already correct position par hai
            if (pos == curr - 1) {
                continue;
            }

            // Step 1: largest element ko front par lao
            if (pos != 0) {
                reverse(arr.begin(), arr.begin() + pos + 1);
                ans.push_back(pos + 1);
            }

            // Step 2: largest element ko correct position par lao
            reverse(arr.begin(), arr.begin() + curr);
            ans.push_back(curr);
        }

        return ans;
    }
};
