class Solution {
public:
    static bool cmp(string a, string b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {

        vector<string> arr;

        // Convert numbers to strings
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(to_string(nums[i]));
        }

        // Sort according to custom rule
        sort(arr.begin(), arr.end(), cmp);

        // If largest is 0, answer is 0
        if (arr[0] == "0")
            return "0";

        // Join all strings
        string ans = "";

        for (int i = 0; i < arr.size(); i++) {
            ans += arr[i];
        }

        return ans;
    }
};
