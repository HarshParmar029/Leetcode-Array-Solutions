class Solution {
public:
    
    // Convert word to lowercase
    string lower(string s) {
        for (char &c : s) {
            c = tolower(c);
        }
        return s;
    }
    
    // Replace every vowel with '*'
    string devowel(string s) {
        s = lower(s);
        
        for (char &c : s) {
            if (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u') {
                c = '*';
            }
        }
        
        return s;
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
        unordered_set<string> exact;
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;
        
        // Build maps from wordlist
        for (string word : wordlist) {
            
            // Exact match
            exact.insert(word);
            
            string low = lower(word);
            
            // Store first case-insensitive match
            if (caseMap.find(low) == caseMap.end()) {
                caseMap[low] = word;
            }
            
            string vowel = devowel(word);
            
            // Store first vowel-error match
            if (vowelMap.find(vowel) == vowelMap.end()) {
                vowelMap[vowel] = word;
            }
        }
        
        vector<string> answer;
        
        for (string query : queries) {
            
            // 1. Exact match
            if (exact.find(query) != exact.end()) {
                answer.push_back(query);
            }
            
            // 2. Case-insensitive match
            else if (caseMap.find(lower(query)) != caseMap.end()) {
                answer.push_back(caseMap[lower(query)]);
            }
            
            // 3. Vowel-error match
            else if (vowelMap.find(devowel(query)) != vowelMap.end()) {
                answer.push_back(vowelMap[devowel(query)]);
            }
            
            // 4. No match
            else {
                answer.push_back("");
            }
        }
        
        return answer;
    }
};
