class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int total = 0;
        int tank = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {

            // Total gas available
            total += gas[i] - cost[i];

            // Gas in our tank
            tank += gas[i] - cost[i];

            // If tank becomes negative
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        // If total gas is less than total cost,
        // completing the circle is impossible
        if (total < 0) {
            return -1;
        }

        return start;
    }
};
