class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if (inorder.empty() || postorder.empty())
            return nullptr;

        int rootValue = postorder.back();

        TreeNode* root = new TreeNode(rootValue);

        int rootIndex = 0;

        while (inorder[rootIndex] != rootValue) {
            rootIndex++;
        }

        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());

        vector<int> leftPostorder(postorder.begin(),
                                  postorder.begin() + rootIndex);

        vector<int> rightPostorder(postorder.begin() + rootIndex,
                                   postorder.end() - 1);

        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);

        return root;
    }
};
