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
    int diameterOfBinaryTree(TreeNode* root) {
        int x = 0 ;
        solve(root, x);
        return x ;
    }

    int solve(TreeNode* root, int &x){
        if(!root){
            return 0 ;
        }

        int lh = solve(root->left, x);
        int rh = solve(root->right, x);

        x = max(lh+rh, x);

        return 1+max(lh,rh);
    }
};