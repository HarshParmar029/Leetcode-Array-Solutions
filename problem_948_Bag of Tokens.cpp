class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(), tokens.end());
        
        int left = 0;
        int right = tokens.size() - 1;
        
        int score = 0;
        int ans = 0;
        
        while (left <= right) {
            
            // Face-up: smallest token
            if (power >= tokens[left]) {
                power -= tokens[left];
                score++;
                ans = max(ans, score);
                left++;
            }
            
            // Face-down: biggest token
            else if (score > 0) {
                power += tokens[right];
                score--;
                right--;
            }
            
            // Cannot make any move
            else {
                break;
            }
        }
        
        return ans;
    }
};
