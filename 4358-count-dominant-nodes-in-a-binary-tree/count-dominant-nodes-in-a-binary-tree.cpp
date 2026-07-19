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
    int ans = 0;
public:
    int countDominantNodes(TreeNode* root) {
        solve(root);
        return ans;
    }

    int solve(TreeNode* root){
        if(!root)return 0;

        int lh = solve(root->left);
        int rh = solve(root->right);

        if(root->val>=lh && root->val>=rh){
            ans++;
        }

        return max({lh, rh, root->val});
    }
};