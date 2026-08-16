class Solution {
public:
    
    TreeNode* solve(vector<int>& preorder, int& index, int minValue, int maxValue) {
        
        // Array khatam
        if (index == preorder.size()) {
            return NULL;
        }
        
        // Current value range ke bahar hai
        if (preorder[index] < minValue || preorder[index] > maxValue) {
            return NULL;
        }
        
        // Current value ko root banao
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        
        // Left subtree
        root->left = solve(preorder, index, minValue, root->val - 1);
        
        // Right subtree
        root->right = solve(preorder, index, root->val + 1, maxValue);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int index = 0;
        
        return solve(preorder, index, 1, 1000);
    }
};
