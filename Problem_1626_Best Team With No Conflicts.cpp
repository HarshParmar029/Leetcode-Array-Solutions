class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        int n = scores.size();

        // Store {age, score}
        vector<pair<int, int>> players;

        for (int i = 0; i < n; i++) {
            players.push_back({ages[i], scores[i]});
        }

        // Sort by age, then score
        sort(players.begin(), players.end());

        // dp[i] = maximum score of team ending at player i
        vector<int> dp(n);

        int answer = 0;

        for (int i = 0; i < n; i++) {

            // We can take player i alone
            dp[i] = players[i].second;

            // Check previous players
            for (int j = 0; j < i; j++) {

                // Previous player's score <= current player's score
                if (players[j].second <= players[i].second) {

                    dp[i] = max(dp[i],
                               dp[j] + players[i].second);
                }
            }

            answer = max(answer, dp[i]);
        }

        return answer;
    }
};
