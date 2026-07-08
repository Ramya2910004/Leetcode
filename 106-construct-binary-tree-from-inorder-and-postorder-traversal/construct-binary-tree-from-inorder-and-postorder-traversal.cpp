/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* constructTree(vector<int>& inorder, int inLeft, int inRight,
                            vector<int>& postorder, int postLeft, int postRight,
                            unordered_map<int, int>& inorderIndex)
    {
        if (inLeft > inRight || postLeft > postRight)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postRight]);

        int rootIndex = inorderIndex[root->val];
        int leftSubtreeSize = rootIndex - inLeft;

        root->left = constructTree(inorder,  inLeft, rootIndex - 1, postorder, postLeft,
                                   postLeft + leftSubtreeSize - 1, inorderIndex);

        root->right = constructTree(inorder, rootIndex + 1, inRight, postorder,              postLeft+leftSubtreeSize, postRight - 1, inorderIndex);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndex;

        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        return constructTree(inorder,
                             0,
                             inorder.size() - 1,
                             postorder,
                             0,
                             postorder.size() - 1,
                             inorderIndex);
    }
};