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
    int height(TreeNode* root, int &ans){
        if(root==NULL) return 0;
        int lefth= height(root->left, ans);
        int righth= height(root->right, ans);
        ans=max(ans, lefth+righth);
        return 1+max(lefth, righth);  
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        height(root,ans);
        return ans;
    }
};