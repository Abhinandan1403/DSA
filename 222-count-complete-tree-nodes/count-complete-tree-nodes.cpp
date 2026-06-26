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
    int countNodes(TreeNode* root) {
        if(!root)return 0;

        int rh = findr(root->right);
        int lh = findl(root->left);

        if(lh == rh)return pow(2, lh)-1;

        return 1 + countNodes(root->left)+countNodes(root->right);
    }

    int findr(TreeNode* root){
        if(!root)return 1;

        return 1+findr(root->right);
    }

    int findl(TreeNode* root){
        if(!root)return 1;

        return 1+findl(root->left);
    }
};