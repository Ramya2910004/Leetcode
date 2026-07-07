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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>res;
        bool zig=true;
        while(!q.empty()){
            int n=q.size();
             vector<int>level(n);
            for(int i=0; i<n; i++){
             TreeNode*ele=q.front();
             q.pop();
             int index= (zig?i:n-1-i);
             level[index]=ele->val;
             if(ele->left){
                q.push(ele->left);
             }
             if(ele->right){
                q.push(ele->right);
             }
            }
            zig=!zig;
            res.push_back(level);
        }
        return res;
    }
};