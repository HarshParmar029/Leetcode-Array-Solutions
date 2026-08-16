class Solution {
public:
    int numTeams(vector<int>& rating) {

        int n = rating.size();
        int answer = 0;

        // Middle soldier
        for (int j = 0; j < n; j++) {

            int leftSmall = 0;
            int leftBig = 0;

            int rightSmall = 0;
            int rightBig = 0;

            // Check left side
            for (int i = 0; i < j; i++) {

                if (rating[i] < rating[j]) {
                    leftSmall++;
                }
                else {
                    leftBig++;
                }
            }

            // Check right side
            for (int k = j + 1; k < n; k++) {

                if (rating[k] > rating[j]) {
                    rightBig++;
                }
                else {
                    rightSmall++;
                }
            }

            // Increasing teams
            answer += leftSmall * rightBig;

            // Decreasing teams
            answer += leftBig * rightSmall;
        }

        return answer;
    }
};
