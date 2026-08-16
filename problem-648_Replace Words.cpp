class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        unordered_set<string> roots;
        
        // Store all roots
        for (string root : dictionary) {
            roots.insert(root);
        }
        
        stringstream ss(sentence);
        string word;
        string ans = "";
        
        while (ss >> word) {
            
            string prefix = "";
            string replacement = word;
            
            // Check every prefix
            for (char ch : word) {
                prefix += ch;
                
                if (roots.count(prefix)) {
                    replacement = prefix;
                    break;
                }
            }
            
            if (!ans.empty()) {
                ans += " ";
            }
            
            ans += replacement;
        }
        
        return ans;
    }
};
