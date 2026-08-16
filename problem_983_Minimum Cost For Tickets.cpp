class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int dp[366] = {0};

        int j = 0;

        for (int day = 1; day <= 365; day++) {

            // Agar aaj travel nahi karna hai
            if (j >= days.size() || days[j] != day) {
                dp[day] = dp[day - 1];
            }

            // Agar aaj travel karna hai
            else {

                // 1 day ticket
                int oneDay = dp[day - 1] + costs[0];

                // 7 day ticket
                int sevenDay = dp[max(0, day - 7)] + costs[1];

                // 30 day ticket
                int thirtyDay = dp[max(0, day - 30)] + costs[2];

                // Minimum cost choose karo
                dp[day] = min(oneDay, min(sevenDay, thirtyDay));

                j++;
            }
        }

        return dp[365];
    }
};
