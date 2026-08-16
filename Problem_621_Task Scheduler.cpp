class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Count frequency of every task
        vector<int> freq(26, 0);

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Find maximum frequency
        int maxFreq = 0;

        for (int i = 0; i < 26; i++) {
            maxFreq = max(maxFreq, freq[i]);
        }

        // Count how many tasks have maximum frequency
        int countMax = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == maxFreq) {
                countMax++;
            }
        }

        // Calculate answer
        int answer = (maxFreq - 1) * (n + 1) + countMax;

        // We cannot have less time than number of tasks
        return max((int)tasks.size(), answer);
    }
};
