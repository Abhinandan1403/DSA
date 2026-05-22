/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q)
            return root;
        if (!root)
            return NULL;

        TreeNode* lh = find(root->left, p, q);
        TreeNode* rh = find(root->right, p, q);

        if (lh && rh)
            return root;
        return rh == NULL ? lh : rh;
    }

    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!root)
            return NULL;

        if (root == p || root == q) {
            return root;
        }

        TreeNode* lh = find(root->left, p, q);
        TreeNode* rh = find(root->right, p, q);

        if (lh && rh)
            return root;
        return rh == NULL ? lh : rh;
    }
};