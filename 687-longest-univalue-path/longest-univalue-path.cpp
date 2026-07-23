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
    int longestUnivaluePath(TreeNode* root) {
        solve(root);
        return max(ans-1, 0);
    }

    int solve(TreeNode* root){
        if(!root){
            return 0;
        }

        if(!root->left && !root->right){
            ans = max(1, ans);
            return 1;
        }

        int l = solve(root->left);
        int r = solve(root->right);

        if(root->left && root->left->val == root->val && root->right && root->right->val == root->val){
            ans = max(ans, 1+l+r);
            return 1+max(l,r);
        }

        else if(root->left && root->left->val == root->val){
            ans = max(ans, 1+l);
            return 1+l;
        }

        else if(root->right && root->right->val == root->val){
            ans = max(ans, 1+r);
            return 1+r;
        }

        return 1;
    }
};