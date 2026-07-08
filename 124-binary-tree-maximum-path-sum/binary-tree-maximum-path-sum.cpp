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
    int Path(TreeNode* root, int &maxi){
      if(root==NULL) return 0;
      int lefth=max(0,Path(root->left,maxi));
      int righth=max(0, Path(root->right, maxi));
      maxi=max(maxi, root->val+lefth+righth);
      return (root->val)+max(lefth, righth);
    }
    int maxPathSum(TreeNode* root) {
     int maxi = INT_MIN;   
     Path(root,maxi);
     return maxi;
    }
};