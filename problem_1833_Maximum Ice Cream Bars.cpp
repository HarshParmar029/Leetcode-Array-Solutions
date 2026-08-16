class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        // Find maximum cost
        int maxCost = 0;

        for (int cost : costs) {
            maxCost = max(maxCost, cost);
        }

        // Count frequency of each cost
        vector<int> count(maxCost + 1, 0);

        for (int cost : costs) {
            count[cost]++;
        }

        int answer = 0;

        // Buy cheapest ice creams first
        for (int price = 1; price <= maxCost; price++) {

            while (count[price] > 0 && coins >= price) {

                coins -= price;
                answer++;
                count[price]--;
            }

            // Cannot buy this price, so cannot buy anything more expensive
            if (coins < price) {
                break;
            }
        }

        return answer;
    }
};
