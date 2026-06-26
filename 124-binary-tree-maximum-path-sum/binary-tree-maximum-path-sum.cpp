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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN ;
        solve(root, ans);
        return ans;
    }

    int solve(TreeNode* root, int& ans ){
        if(!root)return 0;

        int lh = solve(root->left, ans);
        int rh = solve(root->right, ans);

        ans = max({ans, root->val, root->val + lh, root->val + rh, root->val + lh + rh});

        return max({0, root->val, root->val + lh, root->val + rh});
    }
};