class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        // Step 1: Sort folders
        sort(folder.begin(), folder.end());

        vector<string> ans;

        // Step 2: Check every folder
        for (string path : folder) {
            
            // If answer is empty, add first folder
            if (ans.empty()) {
                ans.push_back(path);
            }
            else {
                
                string parent = ans.back();

                // Check whether path is a sub-folder
                if (path.size() > parent.size() &&
                    path.substr(0, parent.size()) == parent &&
                    path[parent.size()] == '/') {
                    
                    // It is a sub-folder
                    // So don't add it
                    continue;
                }
                
                // It is not a sub-folder
                ans.push_back(path);
            }
        }

        return ans;
    }
};
