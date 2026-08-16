class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();

        vector<pair<int, int>> cars;

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort cars by position
        sort(cars.begin(), cars.end());

        int fleets = 0;
        double lastTime = 0;

        // Start from the car closest to target
        for (int i = n - 1; i >= 0; i--) {
            
            double time = (double)(target - cars[i].first) / cars[i].second;

            if (time > lastTime) {
                // New fleet
                fleets++;
                lastTime = time;
            }
            // Otherwise, this car joins the existing fleet
        }

        return fleets;
    }
};
