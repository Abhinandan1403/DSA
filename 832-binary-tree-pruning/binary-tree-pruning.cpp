/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int solve(TreeNode* root) {
        if (!root)
            return 0;

        return root->val + solve(root->left) + solve(root->right);
    }

public:
    TreeNode* pruneTree(TreeNode* root) {
        int val1 = 0, val2 = 0;
        int lh = solve(root->left);
        int rh = solve(root->right);

        if (lh == 0) {
            root->left = NULL;
        }
        if (rh == 0) {
            root->right = NULL;
        }

        if (root->left) {
            pruneTree(root->left);
        }
        if (root->right) {
            pruneTree(root->right);
        }

        if (root->val == 0 && !root->left && !root->right)
            return NULL;

        return root;
    }
};