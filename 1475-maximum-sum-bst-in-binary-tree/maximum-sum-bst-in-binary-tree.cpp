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
    struct NodeInfo {
        bool isBST;
        int sum, mini, maxi;
    };

    int ans = 0;

    NodeInfo solve(TreeNode* root) {
        if (!root)
            return {true, 0, INT_MAX, INT_MIN};

        NodeInfo left = solve(root->left);
        NodeInfo right = solve(root->right);

        if (left.isBST && right.isBST &&
            root->val > left.maxi &&
            root->val < right.mini) {

            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);

            return {
                true,
                currSum,
                min(root->val, left.mini),
                max(root->val, right.maxi)
            };
        }

        return {false, 0, INT_MIN, INT_MAX};
    }

public:
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};